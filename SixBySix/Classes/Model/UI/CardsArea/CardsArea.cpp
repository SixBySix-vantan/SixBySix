//
//  CardsArea.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// カードエリア
// デッキ・手札・墓地のカードを取り付けて表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
// デストラクタ
CCardsArea::~CCardsArea() {
    
    // 手札群の解放
    SAFE_DELETE( this->m_pHands ) ;
    
}


// 初期化
bool CCardsArea::init() {
    // スーパークラスの初期化
    if ( Layer::init() == false )
        return false ;
    
    
    // エリア背景の生成と取り付け
    this->m_pBackGround = Sprite::create( IMAGE_UI_CardsArea ) ;
    this->addChild( this->m_pBackGround ) ;
    
    // デッキ
    this->m_pDeck = CDeckUI::create() ;
    this->m_pDeck->setPosition( -640+100, -70 ) ;
    this->addChild( this->m_pDeck ) ;
    
    // 手札
    this->m_pHands = new vector<CHandUI*>() ;
    for ( int i = 0 ; i < 5 ; i++ ) {
        CHandUI* pHand = CHandUI::create() ;
        pHand->setPosition( -250.f + ( 125.f*i ), 0.f ) ;
        this->addChild( pHand ) ;
        this->m_pHands->push_back( pHand ) ;
    }
    
    // 墓地
    this->m_pCemetery = CCemeteryUI::create() ;
    this->m_pCemetery->setPosition( 640-100, -70 ) ;
    this->addChild( this->m_pCemetery ) ;
    
    
    return true ;
    
}