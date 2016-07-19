//
//  UILayer.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// UIレイヤー
// 各種UIを取り付けてまとめるクラス
//
// このクラスをCGameMainクラスなどに取り付ける
// ===================================================================================================================
// 初期化
bool CUILayer::init() {
    // スーパークラスの初期化
    if ( Layer::init() == false )
        return false ;
	
	
	// カードウィンドウの生成と追加
	auto pCards = CUI_CardsWindow::create() ;
	pCards->setPosition( Position_CardsArea ) ;
	pCards->setZOrder( 1 ) ;
	this->m_UIWindows[UI_WindowType::Cards] = pCards ;
	
    // 詳細ウィンドウの生成と追加
    auto pDetails = CUI_DetailsWindow::create() ;
    pDetails->setPosition( Position_DetailsArea ) ;
	this->m_UIWindows[UI_WindowType::Details] = pDetails ;
    
    // ステータスウィンドウの生成と追加
    auto pMyStatus = CUI_StatusWindow::create() ;
    pMyStatus->setPosition( Position_P1_StatusesArea ) ;
	this->m_UIWindows[UI_WindowType::MyStatus] = pMyStatus ;
	
    auto pOpponentStatus = CUI_StatusWindow::create() ;
    pOpponentStatus->setPosition( Position_P2_StatusesArea ) ;
	this->m_UIWindows[UI_WindowType::OpponentStatus] = pOpponentStatus ;
	
	
	// ウィンドウ群の取り付け
	for ( int i = 0 ; i < this->m_UIWindows.size() ; i++ ) {
		this->addChild( this->m_UIWindows[(UI_WindowType)i] ) ;
	}
	
    return true ;
    
}






