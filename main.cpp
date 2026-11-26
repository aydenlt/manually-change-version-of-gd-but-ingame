
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(ManuallySwitchVersion, MenuLayer) {

    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto menu = CCMenu::create();
        if (!menu) {
            return true;
        }

        auto label = CCLabelBMFont::create(
            "IMPORT APK",
            "goldFont.fnt"
        );

        if (!label) {
            return true;
        }

        label->setScale(0.55f);

        auto button = CCMenuItemLabel::create(
            label,
            this,
            menu_selector(ManuallySwitchVersion::onImportAPK)
        );

        if (!button) {
            return true;
        }

        menu->addChild(button);
        menu->setPosition({
            winSize.width / 2,
            35.f
        });

        this->addChild(menu);

        log::info("Manually Switch Version loaded!");

        return true;
    }

    void onImportAPK(CCObject*) {
        FLAlertLayer::create(
            "Manually Switch Version",
            "APK import is not implemented yet.",
            "OK"
        )->show();
    }
};
