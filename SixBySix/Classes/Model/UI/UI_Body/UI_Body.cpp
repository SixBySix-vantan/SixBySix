//
//  UI_Body.cpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/30.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// UIの実体データ
//
// マウスオーバーラップ判定に利用する
// ===================================================================================================================
/**
 @desc		コンストラクタ
 @param		上
 @param		下
 @param		左
 @param		右
 */
CUI_Body::CUI_Body( int top, int bottom, int left, int right ) {
	this->set( top, bottom, left, right ) ;
}


/**
 @desc		設定
 @param		上
 @param		下
 @param		左
 @param		右
 */
void CUI_Body::set( int top, int bottom, int left, int right ) {
	this->m_top = top ;
	this->m_bottom = bottom ;
	this->m_left = left ;
	this->m_right = right ;
}


/**
 @desc		上の取得
 @return	上
 */
int CUI_Body::getTop() {
	return this->m_top ;
}


/**
 @desc		下の取得
 @return	下
 */
int CUI_Body::getBottom() {
	return this->m_bottom ;
}


/**
 @desc		左の取得
 @return	左
 */
int CUI_Body::getLeft() {
	return this->m_left ;
}


/**
 @desc		右の取得
 @return	右
 */
int CUI_Body::getRight() {
	return this->m_right ;
}










