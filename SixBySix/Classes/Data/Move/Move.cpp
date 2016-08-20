//
//  Move.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


//================================================================================================
//移動クラス
//================================================================================================
//コンストラクタ
CMove::CMove(){}
//デストラクタ
CMove::~CMove(){}


//移動計算
void CMove::moveBy(){
    this->m_pos += this->m_vel;
}

//位置の取得
cocos2d::Point CMove::getPos(){
    return this->m_pos;
}

//位置の設定
void CMove::setPos( cocos2d::Point pos ){
    this->m_pos = pos;
}