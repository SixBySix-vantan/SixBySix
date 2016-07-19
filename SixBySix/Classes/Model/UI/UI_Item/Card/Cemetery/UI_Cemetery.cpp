//
//  UI_Cemetery.cpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/16.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// 墓地表示
// CCardUI クラスを継承した墓地とその枚数を表示するクラス
// ===================================================================================================================
// 初期化
bool CUI_Cemetery::init() {
	// スーパークラスの初期化
	if ( CUI_Card::init() == false )
		return false ;
	
	// テクスチャ
	this->setTexture( IMAGE_UI_Cemetery ) ;
	
	
	
	return true ;
	
}


// =========================================================
// マウスイベント関連
// =========================================================
/**
 @desc		マウスカーソルが重なった時の処理
 */
void CUI_Cemetery::beginOverLap() {
	
	// 起動中のアクションがない場合
	if ( this->getNumberOfRunningActions() == 0 ) {
		
		// OverLapフラグ true
		this->m_isOverLap = true ;
		
		// 拡大と移動を同時に行うアクション
		auto pSpawn = Spawn::create( ScaleTo::create( 0.1f, this->m_scaleRate ), MoveBy::create( 0.1f, Vec2( 0.f, 30.f ) ), NULL ) ;
		//auto pSpawn = Spawn::create( MoveBy::create( 0.1f, Vec2( 0.f, 30.f ) ), NULL ) ;
		// 絶対座標の再設定を呼ぶアクション
		auto pCall = CallFunc::create( [this]() {
			this->setAbsPosition() ;
		} ) ;
		
		
		// 連結させて起動
		this->runAction( Sequence::create( pSpawn, pCall, NULL ) ) ;
		
	}
	
}


/**
 @desc		マウスカーソルが離れた時の処理
 */
void CUI_Cemetery::endOverLap() {
	
	// 起動中のアクションがない場合
	if ( this->getNumberOfRunningActions() == 0 ) {
		
		// OverLapフラグ false
		this->m_isOverLap = false ;
		
		// 縮小と移動を同時に行うアクション
		auto pSpawn = Spawn::create( ScaleTo::create( 0.1f, 1.f ), MoveBy::create( 0.1f, Vec2( 0.f, -30.f ) ), NULL ) ;
		//auto pSpawn = Spawn::create( MoveBy::create( 0.1f, Vec2( 0.f, -30.f ) ), NULL ) ;
		// 絶対座標の再設定を呼ぶアクション
		auto pCall = CallFunc::create( [this]() {
			this->setAbsPosition() ;
		} ) ;
		
		
		// 連結させて起動
		this->runAction( Sequence::create( pSpawn, pCall, NULL ) ) ;
		
	}
	
}