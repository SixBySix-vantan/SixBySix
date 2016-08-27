//
//  AttackCard.cpp
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/09.
//
//

#include "AttackCard.h"
#include "CardFactory.h"


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