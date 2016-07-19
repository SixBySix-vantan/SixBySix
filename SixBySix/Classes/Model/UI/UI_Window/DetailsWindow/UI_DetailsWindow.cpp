//
//  UI_DetailsWindow.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// 詳細ウィンドウ
// 選択中のオブジェクトの詳細を表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
// コンストラクタ
CUI_DetailsWindow::CUI_DetailsWindow() {
	CCLOG( "生成 [詳細ウィンドウ]" ) ;
}


// デストラクタ
CUI_DetailsWindow::~CUI_DetailsWindow() {
	CCLOG( "解放 [詳細ウィンドウ]" ) ;
}


// 初期化
bool CUI_DetailsWindow::init() {
    // 親クラスの初期化
    if ( CUI_Window::init() == false )
        return false ;
    
    // エリア背景
    this->m_pCard = Sprite::create( IMAGE_UI_DetailsArea ) ;
    this->addChild( this->m_pCard ) ;
    
    
    
    return true ;
	
}