//
//  GameMain.cpp
//  SixBySix
//
//  Created by 岡本幸二 on 2016/06/05.
//
//

#include "SixBySix.hpp"

//================================================================================================
//ゲームメインシーン
//================================================================================================
//コンストラクタ
CGameMainLayer::CGameMainLayer(){}

//デストラクタ
CGameMainLayer::~CGameMainLayer(){
    
}

//初期化
bool CGameMainLayer::init(){
    //規定クラスの初期化成功か調べる
    if( !cocos2d::Layer::init() ){
        //失敗ならfalseを返す
        return false;
    }
    
    //成功ならばtrueを返す
    return true;
}

//インスタンス生成
CGameMainLayer *CGameMainLayer::create(){
    //インスタンス生成
    CGameMainLayer *pRet = new (std::nothrow)CGameMainLayer();
    
    //生成成功　かつ　初期化成功か
    if( pRet && pRet->init() ){
        //成功ならばautorelease取り付けて返す
        pRet->autorelease();
        return pRet;
    }
    
    //失敗ならば削除しNULLを返す
    SAFE_DELETE( pRet );
    return NULL;
}

//入場処理
void CGameMainLayer::onEnter(){
    //規定クラスの入場処理を呼び出す
    cocos2d::Layer::onEnter();
    
    //更新処理の呼び出し
    this->scheduleUpdate();
    
    //メインレイヤーの生成　と　取り付け
    this->m_pMainLayer = cocos2d::Layer::create();
    this->addChild( this->m_pMainLayer );
    
    
    //UIレイヤーの生成　と　取り付け
    this->m_pUILayer = cocos2d::Layer::create();
    this->addChild( this->m_pUILayer );
    
    //================================================================================================
    //その他初期化処理
    //================================================================================================
    CUILayer *pUI = CUILayer::create();
    this->m_pUILayer->addChild( pUI );
    
    
    //発表用に追加/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_
    cocos2d::Sprite *pField = cocos2d::Sprite::create( IMAGE_FIELD );
    pField->setPosition(Position_Field);
    this->m_pMainLayer ->addChild( pField );
    
    aaa = CPlayerCharacter::create();
    this->m_pMainLayer->addChild( aaa );
    
    //イベントリスナーを作成
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2( CGameMainLayer::beganTest, this );
    listener->onTouchEnded = CC_CALLBACK_2( CGameMainLayer::releaseTest, this );
    listener->onTouchMoved = CC_CALLBACK_2( CGameMainLayer::moveTest, this );
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this );
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_
    
}

//退場処理
void CGameMainLayer::onExit(){
    //規定クラスの退場処理を呼び出す
    cocos2d::Layer::onExit();
}

//更新処理
void CGameMainLayer::update( float deltaTime ){
    //================================================================================================
    //毎フレーム更新する内容をここに書く
    //================================================================================================
    //フェイズの移動など・・・
    //_/_/_/_/_/_
    
    
    if(this->m_nam >= 180){
    
        CPhaesManager::getInstance()->nextPhaes(this->m_pUILayer);
        this->m_nam = 0;
    }
    this->m_nam++;
    
}

//シーン生成
cocos2d::Scene *CGameMainLayer::createScene(){
    //シーン生成
    cocos2d::Scene *pScene = cocos2d::Scene::create();
    //ゲームメインレイヤー生成
    CGameMainLayer *pLayer = CGameMainLayer::create();
    
    //シーンにゲームメインレイヤー取り付け
    pScene->addChild( pLayer );
    
    //シーンを返す
    return pScene;
}

bool CGameMainLayer::beganTest( cocos2d::Touch* touch, cocos2d::Event* event ){
    //target : ターゲットのスプライト
    CBaseCharacter *target = aaa;
    
    //targetBox : タッチされたスプライトの領域
    Rect targetBox = target->getBoundingBox();
    
    //touchPoint : タッチされた場所...左上0,0になっている為、yは反転させる
    Point touchPoint = Vec2(touch->getLocationInView().x, WINDOW_TOP - touch->getLocationInView().y);
    
    CCLOG( "X::%f", touchPoint.x );
    CCLOG("Y::%f", touchPoint.y );
    
    //touchPointがtargetBoxの中に含まれているか判定
    if (targetBox.containsPoint(touchPoint))
    {
        aaa->touchBeganEvent( touchPoint );
        return true;
    }
    
    return false;
}

void CGameMainLayer::releaseTest( cocos2d::Touch* touch, cocos2d::Event* event ){
    //touchPoint : タッチされた場所...左上0,0になっている為、yは反転させる
    Point touchPoint = Vec2(touch->getLocationInView().x, WINDOW_TOP - touch->getLocationInView().y);
    
    aaa->touchReleaseEvent( touchPoint );
}

void CGameMainLayer::moveTest( cocos2d::Touch* touch, cocos2d::Event* event ){
    //touchPoint : タッチされた場所...左上0,0になっている為、yは反転させる
    Point touchPoint = Vec2(touch->getLocationInView().x, WINDOW_TOP - touch->getLocationInView().y);
    aaa->touchMoveEvent( touchPoint );
}