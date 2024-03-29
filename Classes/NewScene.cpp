#include "NewScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* NewScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto menu_item_1 = MenuItemFont::create("Go Back (pop)", CC_CALLBACK_1(NewScene::GoBack, this));
    auto menu_item_2 = MenuItemFont::create("Go Back (replaceScene)", CC_CALLBACK_1(NewScene::GoBack2, this));
    
    menu_item_1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 3) * 2));
    menu_item_2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 3) * 1));
    
    auto *menu = Menu::create(menu_item_1, menu_item_2, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu);
    
    return true;
}

// go back to previous scene
void NewScene::GoBack(cocos2d::Ref *pSender)
{
	// pop screen
    Director::getInstance()->popScene();
		
}

// replace scene using transition
void NewScene::GoBack2(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
    
	Director::getInstance()->replaceScene(TransitionFlipX::create(1, scene));
}

void NewScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
