//
//  BaseCharacter.cpp
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
CBaseCharacter::CBaseCharacter(){
}

//デストラクタ
CBaseCharacter::~CBaseCharacter(){
}

//初期化
bool CBaseCharacter::init(){
    //初期化に失敗していたらfalseを返す
    if ( !cocos2d::Sprite::init() ) {
        return  false;
    }
    
    //初期化に成功していたらtrueを返す
    return true;
    
}

//インスタンス生成
//CBaseCharacter *CBaseCard::create(){
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
void CBaseCharacter::onEnter(){
    cocos2d::Sprite::onEnter();
    
    //更新処理呼び出し
    this->scheduleUpdate();
}

//退場
void CBaseCharacter::onExit(){
    cocos2d::Sprite::onExit();
    
}

//更新処理
void CBaseCharacter::update( float deltaTime ) {
    this->applyFunc();
}

//反映処理
void CBaseCharacter::applyFunc(){
    //位置データ反映
    this->setPosition( this->m_pMove->getPos() );
    
    //チップデータ反映
    this->setTextureRect( (*this->m_pAnimations)[this->m_state]->getCurrentChip() );
}

//状態確認
void CBaseCharacter::checkState(){
    
    //HPが0以下ならば自身の生存フラグをfalseにする
    if( this->m_pStatus->getHp() <= 0 ){
        this->m_isAlive = false;
    }
}