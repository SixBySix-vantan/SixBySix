//
//  UI_Hand.cpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/16.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// 手札表示
// CUI_Card クラスを継承した手札を表示するクラス
// ===================================================================================================================
// 初期化
bool CUI_Hand::init() {
	// スーパークラスの初期化
	if ( CUI_Card::init() == false )
		return false ;
	
	// テクスチャ
	this->setTexture( IMAGE_UI_Hand ) ;
	// アイコンの生成
	this->createIcon() ;
	
	
	return true ;
	
}


// =========================================================
// マウスイベント関連
// =========================================================
/**
 @desc		マウスカーソルが重なった時の処理
 */
void CUI_Hand::beginOverLap() {
	
	// 起動中のアクションがない場合
	if ( this->getNumberOfRunningActions() == 0 ) {
		
		// OverLapフラグ true
		this->m_isOverLap = true ;
		
		// すべてのアイコンの表示
		this->setVisibleIcon( true ) ;
		
		// 拡大と移動を同時に行うアクション
		auto pSpawn = Spawn::create( ScaleTo::create( 0.05f, this->m_scaleRate ), MoveBy::create( 0.05f, Vec2( 0.f, 25.f ) ), NULL ) ;
		
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
void CUI_Hand::endOverLap() {
	
	// 起動中のアクションがない場合
	if ( this->getNumberOfRunningActions() == 0 ) {
		
		// OverLapフラグ false
		this->m_isOverLap = false ;
		
		// すべてのアイコンの非表示
		this->setVisibleIcon( false ) ;
		
		// 縮小と移動を同時に行うアクション
		auto pSpawn = Spawn::create( ScaleTo::create( 0.05f, 1.f ), MoveBy::create( 0.05f, Vec2( 0.f, -25.f ) ), NULL ) ;
		
		// 絶対座標の再設定を呼ぶアクション
		auto pCall = CallFunc::create( [this]() {
			this->setAbsPosition() ;
		} ) ;
		
		
		// 連結させて起動
		this->runAction( Sequence::create( pSpawn, pCall, NULL ) ) ;
		
	}
	
}


// =========================================================
// アイコン関連
// =========================================================
/**
 @desc		アイコンの生成
 */
void CUI_Hand::createIcon() {
	
	// テスト用
	const float rateY = 1.2f ;
	const float scale = 0.15f ;
	
	
	// 火のアイコン
	auto pFire = Sprite::create( IMAGE_UI_Icon_Fire ) ;
	pFire->setPosition( pFire->getContentSize().width * 0.5f * scale,  this->getContentSize().height * rateY ) ;
	this->m_icons.push_back( pFire ) ;
	
	// 氷のアイコン
	auto pIce = Sprite::create( IMAGE_UI_Icon_Ice ) ;
	pIce->setPosition( pIce->getContentSize().width * 0.5f * scale, this->getContentSize().height * rateY ) ;
	this->m_icons.push_back( pIce ) ;
	
	
	// 透明にしてサイズを合わせて取り付け
	for ( int i = 0 ; i < this->m_icons.size() ; i++ ) {
		
		// 長くなるので一度変数に
		auto pIcon = this->m_icons[ i ] ;
		
		pIcon->setPosition( pIcon->getContentSize().width * (i + 0.5f) * scale, this->getContentSize().height * rateY ) ;
		pIcon->setScale( scale ) ;
		pIcon->setVisible( false ) ;
		this->addChild( pIcon ) ;
		
	}
	
}












