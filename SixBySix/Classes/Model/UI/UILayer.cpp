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
// ===================================================================================================================
// 初期化
bool CUILayer::init() {
    // スーパークラスの初期化
    if ( Layer::init() == false )
        return false ;
    
    // カードエリアの生成と取り付け
    this->m_pCardsArea = CCardsArea::create() ;
    this->m_pCardsArea->setPosition( Position_CardsArea ) ;
    this->addChild( this->m_pCardsArea ) ;
    
    // カード詳細エリアの生成と取り付け
    this->m_pDetailsArea = CDetailsArea::create() ;
    this->m_pDetailsArea->setPosition( Position_DetailsArea ) ;
    this->addChild( this->m_pDetailsArea ) ;
    
    // ステータスエリアの生成と取り付け
    this->m_pStatusesAreas[0] = CStatusesArea::create() ;
    this->m_pStatusesAreas[0]->setPosition( Position_P1_StatusesArea ) ;
    this->addChild( this->m_pStatusesAreas[0] ) ;
    this->m_pStatusesAreas[1] = CStatusesArea::create() ;
    this->m_pStatusesAreas[1]->setPosition( Position_P2_StatusesArea ) ;
    this->addChild( this->m_pStatusesAreas[1] ) ;
    
    return true ;
    
}


















