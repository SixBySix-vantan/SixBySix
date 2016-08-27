//
//  CardFactory.h
//  
//
//  Created by 宇山翔 on 2016/07/04.
//
//

#ifndef ____CardFactory__
#define ____CardFactory__

#include <stdio.h>


///**
// * @brief カードパーツテンプレート工場
// */
//
//class BaseCardPartsFactory{
//public:
//    
//    //アニメーション群の生成
//    virtual std::vector<CAnimation*>* getAnimation() = 0;
//    //移動の生成
//    virtual CMove* getMove() = 0;
//    //アクション群の生成
//    virtual std::vector<CAction*>* getAction() = 0 ;
//    //実体の生成
//    virtual CBody* getBody() = 0;
//    //ステータスの生成
//    virtual CSatus* getStatus() = 0;
//};
//
///**
// *  @brief ベースカードパーツ工場
// */
//
//class CBaseCardPartsFactory : public BaseCardPartsFactory{
//public:
//    //アニメーション群の生成
//    std::vector<CAnimation*>* getAnimation() override {
//        return new std::vector<CAnimation*>() ;
//    }
//    
//    //移動の生成
//    CMove* getMove() override{
//        return new CMove();
//    }
//    
//    //アクション群の生成
//    std::vector<CAction*>* getAction() override {
//        return new std::vector<CAction*>() ;
//    }
//    
//    //実体の生成
//    CBody* getBody() override{
//        return new CMove();
//    }
//    
//    //ステータスの生成
//    CSatus* getStatus() override{
//        return new CSatus();
//    }
//    
//};
//
//
//
///**
// *  @brief ベースカードテンプレート工場
// */
//class CBaseCardtemplateFactory {
//protected:
//    virtual ~CCardtemplateFactory() {}
//    
//    //カードの生成
//    virtual CBaseCard* createCard() = 0;
//    
//    //移動データの生成
//    virtual void setteingMove( CBaseCard* pBaseCard, float posX, float posY ) = 0;
//    
//    //テクスチャの設定
//    virtual void setteingTexture( CBaseCard* pBaseCard ) =0;
//    
//    //アニメーションの設定
//    virtual void setteingAnimation( CBaseCard* pBaseCard ) =0;
//    
//    //アクションの設定
//    virtual void setteingAction( CBaseCard* pBaseCard ) =0;
//    
//    //実体の設定
//    virtual void setteingBody( CBaseCard* pBaseCard ) =0;
//    
//    //初期化設定
//    virtual void setteingInitialize( CBaseCard* BaseCard ) =0;
//    
//public:
//    CBaseCard* create( float posX, float posy ){
//        
//        CBaseCard* pBaseCard = this->createCard();
//        
//        //移動データの設定
//        this->setteingMove( pBaseCard, posX, posY );
//        
//        //テクスチャの設定
//        this->setteingTexture( pBaseCard );
//        
//        //アニメーションの設定
//        this->setteingAnimation( pBaseCard );
//        
//        //アクションの設定
//        this->setteingAction( pBaseCard );
//        
//        //実体の設定
//        this->setteingBody( pBaseCard );
//        
//        //初期化設定
//        this->setteingInitialize( pBaseCard );
//    }
//    
//};
//
//
//
//
///**
// *  @brief ここからシングルトン
// */
//
//class CBaseCardPartsFactoryManager{
//    
//private:
//    //このクラスの共有インスタンス
//    static CBaseCardPartsFactoryManager*　m_pCardFactMgr;
//    
//    //外部で宣言、生成が出来ないようにコンストラクタをprivateにする
//    CBaseCardPartsFactoryManager(){};
//    
//public:
//    //外部で取得できるようにする
//    //CBaseCardPartsFactoryManager::getInstanceで呼べる
//    static CBaseCardPartsFactoryManager* getInstance(){
//        
//        //NULL判定
//        if(CBaseCardPartsFactoryManager::m_pBaseCardPartsFactMgr == NULL ){
//            //NULLなら生成
//            CBaseCardPartsFactoryManager::m_pBaseCardPartsFactMgr = new CBaseCardPartsFactoryManager();
//        }
//        
//        return CBaseCardPartsFactoryManager::m_pBaseCardPartsFactMgr;
//    }
//};
//
//
//
///**
// *  @brief アタックカード生成工場
// */
//class CAttackCardCreateFactory : public CBaseCardtemplateFactory{
//public:
//    virtual ~CAttackCardCreateFactory() {}
//    
//protected:
//    //ベースカードの生成
//    CAttackCard* createCard() override{
//        
//        //ベースカードの生成
//        CAttackCard* pAttackCard = CAttackCard::create();
//        
//        //アニメーション群の生成と取り付け
//        pAttackCard->m_pAnimation = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getAnimation();
//        
//        //移動の生成と取り付け
//        pAttackCard->m_pMove = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getMove();
//        
//        //アクション群の生成と取り付け
//        pAttackCard->m_pAction = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getAction();
//        
//        //実体の生成と取り付け
//        pAttackCard->m_pBody = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getBody();
//        
//        return pAttackCard;
//    }
//};
//
///**
// *  @brief 基本アタックカード生成工場
// */
//class CNomalAttackCardCreateFactory : public CAttackCardCreateFactory{
//protected:
//    //移動データの設定
//    void setteingMove( CAttackCard* pAttackCard, float posX, float posY ) {}
//    
//    //移動データの生成
//    void setteingMove( CAttackCard* pAttackCard, float posX, float posY ) {}
//    
//    //テクスチャの設定
//    void setteingTexture( CAttackCard* pAttackCard ) {}
//    
//    //アニメーションの設定
//    void setteingAnimation( CAttackCard* pAttackCard ) {}
//    
//    //アクションの設定
//    void setteingAction( CAttackCard* pAttackCard ) {}
//    
//    //実体の設定
//    void setteingBody( CAttackCard* pAttackCard ) {}
//    
//    //初期化設定
//    void setteingInitialize( CAttackCard* pAttackCard ) {}
//    
//public:
//    CAttackCard* create( float posX, float posy ){
//        
//        CAttackCard* pAttackCard = this->createCard();
//        
//        //移動データの設定
//        this->setteingMove( pAttackCard, posX, posY );
//        
//        //テクスチャの設定
//        this->setteingTexture( pAttackCard );
//        
//        //アニメーションの設定
//        this->setteingAnimation( pAttackCard );
//        
//        //アクションの設定
//        this->setteingAction( pAttackCard );
//        
//        //実体の設定
//        this->setteingBody( pAttackCard );
//        
//        //初期化設定
//        this->setteingInitialize( pAttackCard );
//    }
//    
//    
//};
//
//
//
///**
// *  @brief サポートカード生成工場
// */
//class CSupportCardCreateFactory : public CBaseCardtemplateFactory{
//public:
//    virtual ~CSupportCardCreateFactory() {}
//    
//protected:
//    //ベースカードの生成
//    CSupportCard* createCard() override{
//        
//        //ベースカードの生成
//        CSupportCard* pAttackCard = CAttackCard::create();
//        
//        //アニメーション群の生成と取り付け
//        pSupportCard->m_pAnimation = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getAnimation();
//        
//        //移動の生成と取り付け
//        pSupportCard->m_pMove = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getMove();
//        
//        //アクション群の生成と取り付け
//        pSupportCard->m_pAction = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getAction();
//        
//        //実体の生成と取り付け
//        pSupportCard->m_pBody = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getBody();
//        
//        return pSupportCard;
//    }
//};
//
///**
// *  @brief 基本サポートカード生成工場
// */
//
//class CNomalSupportCreateFactory : public CSupportCardCreateFactory{
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
//    
//    
//};
//
///*
// *  @brief プレイスカード生成工場
// */
//
//class CSupportCardCreateFactory : public CBaseCardtemplateFactory{
//public:
//    virtual ~CSupportCardCreateFactory() {}
//    
//protected:
//    //ベースカードの生成
//    CSupportCard* createCard() override {
//        
//        //ベースカードの生成
//        CSupportCard* pAttackCard = CAttackCard::create();
//        
//        //アニメーション群の生成と取り付け
//        pSupportCard->m_pAnimation = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getAnimation();
//        
//        //移動の生成と取り付け
//        pSupportCard->m_pMove = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getMove();
//        
//        //アクション群の生成と取り付け
//        pSupportCard->m_pAction = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getAction();
//        
//        //実体の生成と取り付け
//        pSupportCard->m_pBody = CBaseCardPartsFactoryManager::getInstance()->m_baseCardPartsFactory->getBody();
//        
//        return pSupportCard;
//    }
//};
//
///**
// *  @brief 基本プレイスカード生成工場
// */
//
//class CNomalSupportCreateFactory : public CPlaceCardCreateFactory{
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
//
//
///**
// *  @brief ベースカード生成工場管理
// */
//
//
//class CBaseCardCreateFactoryManager {
//private:
//    // 共有インスタンス
//    static CBaseCardCreateFactoryManager* m_pCardFactMgr ;
//    
//    // コンストラクタ
//    CBaseCardCreateFactoryManager() {
//        // 基本カード生成工場の生成
//        this->m_pBaseCardCraeteFactory = new CBaseCardCreateFactory() ;
//    }
//    
//public:
//    // デストラクタ
//    ~CBaseCardCreateFactoryManager() {
//        // 基本カード生成工場の破棄
//        SAFE_DELETE( this->m_pBaseCardCraeteFactory ) ;
//    }
//    
//    // 共有インスタンスの取得
//    static CBaseCardCreateFactoryManager* getInstance() {
//        if ( m_pCardFactMgr == NULL ) {
//            m_pCardFactMgr = new CBaseCardCreateFactoryManager() ;
//        }
//        return m_pCardFactMgr ;
//    }
//    
//    // 共有インスタンスの破棄
//    static void removeInstance() {
//        SAFE_DELETE( m_pCardFactMgr ) ;
//    }
//    
//public:
//    // 基本カード生成工場
//    CBaseCardCreateFactory* m_pBaseCardCraeteFactory = NULL ;
//} ;
//
//
//
//
//
//

#endif /* defined(____CardFactory__) */
