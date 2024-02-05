#include "Global.h"
#include "include_all.h"

#include <GMLIB/Mod/CustomPacks.h>

namespace plugin {

Plugin::Plugin(ll::plugin::NativePlugin& self) : mSelf(self) {
    // Code for loading the plugin goes here.
    GMLIB::loadLib();
    GMLIB::Mod::CustomPacks::addCustomPackPath("./Addons");
}

bool Plugin::enable() {
    // Codes
    GMLIB::enableLib();
    return true;
}

bool Plugin::disable() {
    logger.info("Disabling GMLIB...");
    // Code for disabling the plugin goes here.
    logger.info("GMLIB Disabled!");
    return true;
}

} // namespace plugin