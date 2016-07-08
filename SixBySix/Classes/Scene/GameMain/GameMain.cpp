//
//  GameMain.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/05.
//
//

//================================================================================================
//追加インクルード
//================================================================================================
#include "GameMain.hpp"
#include "Constants.hpp"


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
    
    //================================================================================================
    //その他初期化処理
    //================================================================================================
        
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