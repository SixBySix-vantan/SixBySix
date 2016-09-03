//
//  AttackCard.cpp
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/09.
//
//

#include "CardFactory.h"
#include "SixBySix.hpp"

//================================================================================================
//攻撃カード
//================================================================================================
//コンストラクタ
CAttackCard::CAttackCard(){
    
}

//デストラクタ
CAttackCard::~CAttackCard(){
    
}

//初期化
bool CAttackCard::init(){
    //基底クラスの初期化を呼ぶ
    if( !CBaseCard::init() ){
        //初期化失敗ならfalseを返す
        return false;
    }
    
    this->m_pCardStatus = new CCardStatus( 2, 2 );
    //this->m_pCardEffect =
    
    return true;
}

//インスタンス生成
CAttackCard *CAttackCard::create(){
    //インスタンス生成
    CAttackCard *pRet = new (std::nothrow) CAttackCard();
    
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

//入場処理
void CAttackCard::onEnter(){
    
}

//退場
void CAttackCard::onExit(){
    
}

//更新処理
//void CAttackCard::update( float deltaTime ){
//
//}

//押された時のイベント
void CAttackCard::touchBeganEvent( cocos2d::Point pos){
    
}

//離された時のイベント
void CAttackCard::touchReleaseEvent( cocos2d::Point pos ){
    
}

//動かされた時のイベント
void CAttackCard::touchMoveEvent( cocos2d::Point pos ){
    
}

//キャンセル時のイベント
void CAttackCard::touchCancelEvent( cocos2d::Point pos ){
    
}

///**
// *  @brief 基本プレイスカード生成工場
// */
//
//CNomalSupportCreateFactory : public CPlaceCardCreateFactory{
//protected:
//    //移動データの設定
//    void setteingMove( CSupportCard* pASupportCard, float posX, float posY ) {}
//
//    //移動データの生成
//    void setteingMove( CSupportCard* pSupportCard, float posX, float posY ) {}
//
//    //テクスチャの設定
//    void setteingTexture( CSupportCard* pSupportCard ) {}
//
//    //アニメーションの設定
//    void setteingAnimation( CSupportCard* pSupportCard ) {}
//
//    //アクションの設定
//    void setteingAction( CSupportCard* pSupportCard ) {}
//
//    //実体の設定
//    void setteingBody( CSupportCard* pSupportCard ) {}
//
//    //初期化設定
//    void setteingInitialize( CSupportCard* pSupportCard ) {}
//
//public:
//    CSupportCard* create( float posX, float posy ){
//
//        CSupportCard* pSupportCard = this->createCard();
//
//        //移動データの設定
//        this->setteingMove( pSupportCard, posX, posY );
//
//        //テクスチャの設定
//        this->setteingTexture( pSupportCard );
//
//        //アニメーションの設定
//        this->setteingAnimation( pSupportCard );
//
//        //アクションの設定
//        this->setteingAction( pSupportCard );
//
//        //実体の設定
//        this->setteingBody( pSupportCard );
//
//        //初期化設定
//        this->setteingInitialize( pSupportCard );
//    }
//};



////=========================================================================
////	ベースカードパーツ工場管理
////=========================================================================
//// 共有インスタンス本体
//CBaseCardPartsFactoryManager* CBaseCardPartsFactoryManager::m_pCardFactMgr = NULL;
//
//
////=========================================================================
////	カード生成工場管理
////=========================================================================
//// 共有インスタンス本体
//CBaseCardCreateFactoryManager* CBaseCardCreateFactoryManager::m_pCardFactMgr = NULL;