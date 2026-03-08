#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto sprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
        auto btn = CCMenuItemSpriteExtra::create(
            sprite, this, menu_selector(MyMenuLayer::onVinzBtn)
        );

        auto menu = this->getChildByID("top-right-menu");
        if (menu) {
            menu->addChild(btn);
            menu->updateLayout();
        }
        return true;
    }

    void onVinzBtn(CCObject*) {
        FLAlertLayer::create("Halo Vinz!", "Hello World dari Mod Geode Lu!", "OK")->show();
    }
};
