//
//  UI_CardsWindow.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// カードウィンドウ
// デッキ・手札・墓地のカードを取り付けて表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
// コンストラクタ
CUI_CardsWindow::CUI_CardsWindow() {
	CCLOG( "生成 [カードウィンドウ]" ) ;
}


// デストラクタ
CUI_CardsWindow::~CUI_CardsWindow() {
	CCLOG( "解放 [カードウィンドウ]" ) ;
}


// 初期化
bool CUI_CardsWindow::init() {
	// 親クラスの初期化
	if ( CUI_Window::init() == false )
		return false ;
	
    
    // エリア背景の生成と取り付け
    this->m_pBackGround = Sprite::create( IMAGE_UI_CardsArea ) ;
    this->addChild( this->m_pBackGround ) ;
	
    // デッキ
	this->m_pDeck = CUI_Deck::create() ;
	this->m_pDeck->setPosition( Point( -540.f, -70.f ) ) ;
    this->addChild( this->m_pDeck ) ;
	
	
    // 手札
    for ( int i = 0 ; i < 5 ; i++ ) {
		auto pHand = CUI_Hand::create() ;
		pHand->setPosition( Point( -250.f + 125.f * i, 0.f ) ) ;
        this->m_hands.push_back( pHand ) ;
		this->addChild( pHand ) ;
    }
	 
    // 墓地
	this->m_pCemetery = CUI_Cemetery::create() ;
	this->m_pCemetery->setPosition( Point( 540.f, -70.f ) ) ;
    this->addChild( this->m_pCemetery ) ;
    
    
    return true ;
    
}