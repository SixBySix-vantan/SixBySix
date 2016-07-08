//
//  DetailsArea.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// 詳細エリア
// 選択中のオブジェクトの詳細を表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
// 初期化
bool CDetailsArea::init() {
    // スーパークラスの初期化
    if ( Layer::init() == false )
        return false ;
    
    // エリア背景
    this->m_pCard = Sprite::create( IMAGE_UI_DetailsArea ) ;
    this->addChild( this->m_pCard ) ;
    
    
    
    return true ;
    
}