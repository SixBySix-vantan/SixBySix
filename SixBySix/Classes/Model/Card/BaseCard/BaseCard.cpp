//
//  BaseCard.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/11.
//
//

#include "SixBySix.hpp"

//================================================================================================
//基底カードクラス
//================================================================================================
//コンストラクタ
CBaseCard::CBaseCard(){
}

//デストラクタ
CBaseCard::~CBaseCard(){
}

//初期化
bool CBaseCard::init(){
    //初期化に失敗していたらfalseを返す
    if ( !cocos2d::Sprite::init() ) {
        return  false;
    }
    
    //初期化に成功していたらtrueを返す
    return true;
    
}

//インスタンス生成
//CBaseCard *CBaseCard::create(){
//    //インスタンス生成
//    CBaseCard *pRet = new (std::nothrow) CBaseCard();
//
//    //生成成功　かつ　初期化成功　していれば
//    if ( pRet && pRet->init() ) {
//        //autoreleaseをとりつけて返す
//        pRet->autorelease();
//        return pRet;
//    }
//
//    //失敗していれば削除しnullを返す
//    SAFE_DELETE( pRet );
//    return NULL;
//
//}


//入場処理
void CBaseCard::onEnter(){
    cocos2d::Sprite::onEnter();
    
    //更新処理呼び出し
    this->scheduleUpdate();
}

//退場
void CBaseCard::onExit(){
    cocos2d::Sprite::onExit();
    
}

//更新処理
void CBaseCard::update( float deltaTime ) {
}