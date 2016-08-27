//
//  HandCard.cpp
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/09.
//
//

#include "HandCard.h"

/**
 *  シーンを作成する。
 *
 *  @return シーン
 */
Scene* HandCard::createScene()
{
    // 'scene' は autorelease オブジェクト
    auto scene = Scene::create();
    
    // 'layer' は autorelease オブジェクト
    auto layer = HandCard::create();
    
    // レイヤーをシーンの子として追加する。
    scene->addChild(layer);
    
    // シーンを返す。
    return scene;
}

/**
 *  インスタンスを初期化する。
 *
 *  @return 成功したらtrue
 */
bool HandCard::init()
{
    //////////////////////////////
    // 1. 親クラスを初期化する。
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面サイズを取得する。
    visibleSize = Director::getInstance()->getVisibleSize();
    // 画面の原点を取得する。
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. クリックすると終了する”X”画像付きのメニュー項目を追加する。これは変更してもよい。
    
    // プログラムを終了する"close"アイコンを追加する。これは autorelease オブジェクト。
    auto closeItem = MenuItemImage::create(
                                           "test.png",
                                           "test.png",
                                           CC_CALLBACK_1(HandCard::menuCloseCallback, this));
    
    closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // メニューを作成する。これは autorelease オブジェクト。
    auto menu = Menu::create(closeItem, NULL);
    // メニューの位置を設定する。
    menu->setPosition(Point::ZERO);
    // メニューを子レイヤーとして追加する。
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. 独自のコードを追加する。
    this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    
    // ラベルを作成し、初期化する。
    auto label = LabelTTF::create("whack a mole sample", "Arial", 24);
    
    // 画面の中央にラベルを位置づける。
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // ラベルをレイヤーの子として追加する。
    this->addChild(label, 1);
    
    // cocosアイコンを追加する。
    sprite = Sprite::create("test.png");
    
    // スプライトを画面の中央に位置づける。
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // スプライトをレイヤーの子として追加する。
    this->addChild(sprite, 0);
    
    // シングルタッチイベントリスナーを作成する。
    auto listener1 = EventListenerTouchOneByOne::create();
    // スワロータッチモードにするとonTouchBeganメソッドはタッチイベントは他では使われない。
    listener1->setSwallowTouches(true);
    
    // onTouchBeganイベントコールバック関数実装のラムダ式の例
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        // event->getCurrentTarget() は、リスナーのsceneGraphPriorityの優先順に対象オブジェクトを返す。
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        // ボタンに対する相対的な位置を取得する。
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        // コンテンツのサイズを取得する。
        Size s = target->getContentSize();
        // コンテンツ矩形を作成する。
        Rect rect = Rect(0, 0, s.width, s.height);
        
        // クリックエリアをチェックする。
        if (rect.containsPoint(locationInNode))
        {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            // 不透明度を変更する。
            target->setOpacity(180);
            return true;
        }
        return false;
    };
    
    // タッチが移動した場合
    listener1->onTouchMoved = [](Touch* touch, Event* event) {
        // ターゲットを取得する。
        // auto target = static_cast<Sprite*>(event->getCurrentTarget());
        // ここに移動した場合の処理を書く。touch->getDelta()で移動量が取得できる。
    };
    
    // タッチイベントが終了した場合
    listener1->onTouchEnded = [=](Touch* touch, Event* event) {
        // ターゲットを取得する。
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        // ここに終了した場合の処理を書く。
        log("sprite onTouchesEnded.. ");
        // スプライトを画面の中央に位置づける。
        sprite->setPosition(*getNextPosition());
        // 不透明度を元に戻す。
        target->setOpacity(255);
    };
    
    // イベントリスナーをスプライトに追加する。
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite);
    
    return true;
}

/**
 *  メニューの"Close"が選択された場合のコールバック関数。
 *
 *  @param pSender 送信元
 */
void HandCard::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    // ディレクタを終了する。
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/**
 *
 *  画面上のランダムな位置を取得する。
 *
 *  @return 画面上のランダムな位置
 */
Point* HandCard::getNextPosition()
{

}