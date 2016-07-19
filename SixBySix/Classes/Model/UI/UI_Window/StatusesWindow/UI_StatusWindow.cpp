//
//  UI_StatusWindow.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// ステータスウィンドウ
// 両プレイヤーのステータスを表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
// コンストラクタ
CUI_StatusWindow::CUI_StatusWindow() {
	CCLOG( "生成 [ステータスウィンドウ]" ) ;
}


// デストラクタ
CUI_StatusWindow::~CUI_StatusWindow() {
	CCLOG( "解放 [ステータスウィンドウ]" ) ;
}


// 初期化
bool CUI_StatusWindow::init() {
    // 親クラスの初期化
    if ( CUI_Window::init() == false )
        return false ;
	
	
    // 背景
    this->m_pBackGround = Sprite::create( IMAGE_UI_StatusesArea ) ;
    this->addChild( this->m_pBackGround ) ;
    
    
    return true ;
    
}