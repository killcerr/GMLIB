#include "Global.h"
#include <GMLIB/Mod/CustomBiome.h>
#include <GMLIB/Server/LevelAPI.h>

// Add "Parameter() = default" to Parameter.h

namespace GMLIB::Mod {

std::unordered_map<std::string, BiomeData> mClimates;
std::vector<std::string>                   mNewBiomes;
bool                                       mCustomBiomeEnabled = false;

void CustomBiome::registerBiomeClimates(std::string id, BiomeData data) {
    mClimates[id]       = data;
    mCustomBiomeEnabled = true;
    GMLIB_Level::addExperimentsRequire((AllExperiments)7);
}

// 6 | ExperimentalHoliday
// 7 | ExperimentalBiomes
// 8 | ExperimentalCreatorFeatures
// 9 | ExperimentalGameTest
// 10 | ExperimentalMolangFeatures
// 12 | ExperimentalCameras
// 15 | ExperimentalVillagerTradesRebalance
// 16 | ExperimentalUpdateAnnounced2023

void CustomBiome::registerEmptyBiome(std::string id, BiomeData data) {
    mNewBiomes.push_back(id);
    CustomBiome::registerBiomeClimates(id, data);
}

LL_AUTO_TYPE_INSTANCE_HOOK(
    OverworldBiomeBuilderHook,
    HookPriority::Highest,
    OverworldBiomeBuilder,
    "?addBiomes@OverworldBiomeBuilder@@QEBAXAEAV?$vector@UBiomeNoiseTarget@@V?$"
    "allocator@UBiomeNoiseTarget@@@std@@@std@@AEBVBiomeRegistry@@@Z",
    void,
    std::vector<BiomeNoiseTarget>* a1,
    BiomeRegistry*                 a2
) {
    origin(a1, a2);
    if (mCustomBiomeEnabled) {
        for (auto& [name, data] : mClimates) {
            if (data.mType == BiomeType::Surface) {
                this->_addSurfaceBiome(
                    *a1,
                    data.mTemperatureRange,
                    data.mHumidityRange,
                    data.mContinentalnessRange,
                    data.mErosionRange,
                    data.mWeirdnessRange,
                    data.mOffset,
                    a2->lookupByName(name)
                );
            } else if (data.mType == BiomeType::Underground) {
                this->_addUndergroundBiome(
                    *a1,
                    data.mTemperatureRange,
                    data.mHumidityRange,
                    data.mContinentalnessRange,
                    data.mErosionRange,
                    data.mWeirdnessRange,
                    data.mOffset,
                    a2->lookupByName(name)
                );
            } else {
                __assume(false);
            }
        }
        mClimates.clear();
    }
}

LL_AUTO_STATIC_HOOK(
    BiomeRegistryHook,
    HookPriority::Highest,
    "?initBiomes@VanillaBiomes@@SAXAEAVBiomeRegistry@@AEBUSpawnSettings@"
    "@AEBVBaseGameVersion@@AEBVExperiments@@@Z",
    void,
    BiomeRegistry* a1,
    void*          a2,
    void*          a3,
    void*          a4
) {
    if (mCustomBiomeEnabled) {
        for (auto& name : mNewBiomes) {
            a1->registerBiome(name);
        }
    }
    return origin(a1, a2, a3, a4);
}

LL_AUTO_INSTANCE_HOOK(ClientGen, HookPriority::Highest, "?isClientSideGenEnabled@PropertiesSettings@@QEBA_NXZ", bool) {
    if (mCustomBiomeEnabled) {
        return false;
    }
    return origin();
}

}