//
//  GameMain.hpp
//  SixBySix
//
//  Created by 岡本幸二 on 2016/06/05.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================



//前方宣言
class CPlayerCharacter;

//================================================================================================
//ゲームメインレイヤー
//================================================================================================
class CGameMainLayer : cocos2d::Layer{
protected:
    //コンストラクタ
    CGameMainLayer();
    //デストラクタ
    ~CGameMainLayer();
    
    //初期化
    bool init() override;
    
    //インスタンス生成
    static CGameMainLayer *create();
    
    //入場処理
    void onEnter() override;
    
    //退場処理
    void onExit() override;
    
    //更新処理
    void update( float deltaTime ) override;
    
public:
    //シーン生成
    static cocos2d::Scene *createScene();

    
public:
    //================================================================================================
    //メンバ変数とメンバ関数の追加
    //================================================================================================
    //メインレイヤー
    cocos2d::Layer *m_pMainLayer = NULL;
    
    //UIレイヤー
    cocos2d::Layer *m_pUILayer = NULL;
    
    //_/_/_/_/_/_
    //テスト用変数
    int m_nam = 0;
    //_/_/_/_/_/_
    
    //発表用に追加
    CPlayerCharacter *aaa = NULL;
    bool beganTest( cocos2d::Touch* touch, cocos2d::Event* event );
    void releaseTest( cocos2d::Touch* touch, cocos2d::Event* event );
    void moveTest( cocos2d::Touch* touch, cocos2d::Event* event );

    
};