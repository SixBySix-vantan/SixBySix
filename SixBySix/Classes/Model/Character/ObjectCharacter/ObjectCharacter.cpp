//
//  ObjectCharacter.cpp
//  SixBySix
//
//  Created by 後藤　弘哉 on 2016/07/16.
//
//


//===========================================
// 追加のインクルードここから
//===========================================
#include "ObjectCharacter.hpp"

//==================================================
// プレイヤーキャラクターのメンバ関数のコードの追加はここから
//==================================================

// コンストラクタ
CObjectCharacter::CObjectCharacter(){
    
}

// デストラクタ
CObjectCharacter::~CObjectCharacter(){
    
}

// 初期化処理
bool CObjectCharacter::init(){
    
    // 石クラスの初期化
    if(CObjectCharacter::init() == false){
        CCLOG("オブジェクト石の初期化に失敗");
        return false;
    }
    
    
    // テクスチャの設定
    this->setTexture("Object.png");
    
    // アニメーションデーター群
    this->m_pAnimations = new std::vector<CAnimation*>;
    // アニメーションなしの設定
    this->m_pAnimations->push_back(new CChipNotAnimation());
    
    // ステータスの設定(プレイヤーアタック、オブジェクトアタック、maxHp)
    this->m_pStatus->set(0, 0, 10);
    
    // 有効フラグ
    this->m_activeFlag = true;
    
    // 反映処理
    this->applyFunc();
    
    return true;
}

// 更新処理
void CObjectCharacter::update(float deltaTime){
    
}

//押された時のイベント
void CObjectCharacter::touchBeganEvent( cocos2d::Point pos ){
    
}

//離された時のイベント
void CObjectCharacter::touchReleaseEvent( cocos2d::Point pos ){
    
}

//動かされた時のイベント
void CObjectCharacter::touchMoveEvent( cocos2d::Point pos ){
    
}

//キャンセル時のイベント
void CObjectCharacter::touchCancelEvent( cocos2d::Point pos ){
    
}

