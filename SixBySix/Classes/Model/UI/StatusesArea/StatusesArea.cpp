//
//  StatusesArea.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// ステータスエリア
// 両プレイヤーのステータスを表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
// 初期化
bool CStatusesArea::init() {
    // スーパークラスの初期化
    if ( Layer::init() == false )
        return false ;
    
    // エリア背景
    this->m_pBack = Sprite::create( IMAGE_UI_StatusesArea ) ;
    this->addChild( this->m_pBack ) ;
    
    
    return true ;
    
}