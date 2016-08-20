//
//  PlayerCharacter.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/07/16.
//
//

#include "SixBySix.hpp"

//================================================================================================
//プレイヤーキャラクター
//================================================================================================
//コンストラクタ
CPlayerCharacter::CPlayerCharacter(){
    
}

//デストラクタ
CPlayerCharacter::~CPlayerCharacter(){
    
}

//初期化
bool CPlayerCharacter::init() {
    //基底クラスのinit()を呼び出す
    if( !CBaseCharacter::init() ){
        //失敗ならばfalseを返す
        return false;
    }
    
    
    //================================================================================================
    //ここはあとで工場に移動予定
    //================================================================================================
    this->setTexture( IMAGE_Player_Character );
    
    //ステータスの生成
    this->m_pStatus = new CStatus();
    this->m_pStatus->set( 0, 0, 5 );
    
    //移動データ生成
    this->m_pMove = new CMove();
    this->m_pMove->setPos( WINDOW_CENTER );
    
    //アニメーションデータの生成
    this->m_pAnimations = new std::vector<CAnimation*>;
    this->m_pAnimations->push_back( new CChipNotAnimation() );
    (*this->m_pAnimations)[0]->addChipData( new CChip( 0, 0, 100, 100 ) );
    
    //有効フラグ設定
    this->m_activeFlag = true;
    
    return true;
}

//インスタンス生成
CPlayerCharacter *CPlayerCharacter::create(){
    //インスタンス生成
    CPlayerCharacter *pRet = new (std::nothrow) CPlayerCharacter();
    
    //生成成功　かつ　初期化成功　していれば
    if ( pRet && pRet->init() ) {
        //autoreleaseをとりつけて返す
        pRet->autorelease();
        return pRet;
    }
    
    //失敗していれば削除しnullを返す
    SAFE_DELETE( pRet );
    return NULL;

}

//押された時のイベント
bool CPlayerCharacter::touchBeganEvent(){
    CCLOG("押された");
}

//離された時のイベント
void CPlayerCharacter::touchReleaseEvent(){
    CCLOG("離された");
}

//動かされた時のイベント
void CPlayerCharacter::touchMoveEvent(){
    CCLOG("うごくよねー");
}

//キャンセル時のイベント
void CPlayerCharacter::touchCancelEvent() {
    CCLOG("ひぇっ...");
}