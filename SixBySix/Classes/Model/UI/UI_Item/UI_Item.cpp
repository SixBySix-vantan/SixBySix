//
//  UI_Item.cpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/16.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// UIアイテム
// UI一つそのもの
//
// マウス入力を受け付けるUI
// 入力による挙動は継承先で定義する
// ===================================================================================================================
// 初期化
bool CUI_Sprite::init() {
	// 親クラスの初期化
	if ( Sprite::init() == false )
		return false ;
	
	// マウスイベントの受け付け設定
	this->setMouseEvent() ;
	
	return true ;
	
}


/**
 @desc		入場処理
 */
void CUI_Sprite::onEnter() {
	Sprite::onEnter() ;
	
	// 絶対位置の設定
	this->setAbsPosition() ;
	
	
}


/**
 @desc		退場処理
 */
void CUI_Sprite::onExit() {
	Sprite::onExit() ;
	
}


/**
 @desc		絶対座標の設定
 */
void CUI_Sprite::setAbsPosition() {
	
	// シーンの取得(１番の親ノード)
	cocos2d::Node* pScene = cocos2d::Director::getInstance()->getRunningScene() ;
	
	// 現在参照中のノード
	cocos2d::Node* pCurrentNode = this->getParent() ;
	// 全相対座標を計算する変数
	cocos2d::Point pos = this->getPosition() ;
	
	// シーンにたどり着くまで親ノードをさかのぼる
	while ( pCurrentNode != pScene ) {
		
		// 相対位置を加算
		pos = pCurrentNode->getPosition() + pos ;
		// 現在参照中のノードをその親に設定
		pCurrentNode = pCurrentNode->getParent() ;
		
	}
	
	// 計算結果を自身の絶対位置に設定
	this->m_absPosition = pos ;
	
	// OverLap判定を行う矩形の原点の設定
	this->setRectOriginPosition() ;
	
}


/**
 @desc		絶対座標の取得
 @return	絶対座標
 */
cocos2d::Point CUI_Sprite::getAbsPosition() {
	return this->m_absPosition ;
}


/**
 @desc		OverLap判定を行う矩形の原点の設定
 @tips		絶対座標を設定後に呼び出される
 */
void CUI_Sprite::setRectOriginPosition() {
	
	float posX = this->m_absPosition.x - this->getContentSize().width * this->getScaleX() * 0.5 ;
	float posY = this->m_absPosition.y + this->getContentSize().height * this->getScaleY() * 0.5 ;
	
	this->m_rectOriginPos = Point( posX, posY ) ;
	
}


// =========================================================
// マウスイベント関連
// =========================================================
/**
 @desc		マウス入力イベントの受け付け設定
 */
void CUI_Sprite::setMouseEvent() {
	
	// マウスイベントの登録
	auto pMouseListener = EventListenerMouse::create() ;
	pMouseListener->onMouseMove = CC_CALLBACK_1( CUI_Sprite::onMouseMove, this ) ;
	pMouseListener->onMouseDown = CC_CALLBACK_1( CUI_Sprite::onMouseDown, this ) ;
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( pMouseListener, this ) ;
	
}


/**
 @desc		マウスを動かした際のイベント
 @param		マウスイベント
 */
void CUI_Sprite::onMouseMove( EventMouse* pMouseEvent ) {
	
	// マウスカーソルが重なっている場合
	if ( this->isCursorOverLap( Point( pMouseEvent->getCursorX(), pMouseEvent->getCursorY() ) ) ) {
		
		// 条件を満たしている場合
		if ( this->checkCondition() == true ) {
			if ( this->m_isOverLap == false )
				this->beginOverLap() ;
		}
		
		
	// マウスカーソルが重なっていない場合
	} else {
		
		if ( this->m_isOverLap == true ) {
			if ( this->m_isOverLap == true )
				this->endOverLap() ;
		}
		
	}
	
}


/**
 @desc		マウスを左クリックした際のイベント
 @param		マウスイベント
 */
void CUI_Sprite::onMouseDown( EventMouse* pMouseEvent ) {
	
	// クリックした座標が重なっているかどうか調べる
	if ( this->isCursorOverLap( Point( pMouseEvent->getCursorX(), pMouseEvent->getCursorY() ) ) ) {
		
		//CCLOG( "X : %f   Y : %f", pMouseEvent->getCursorX(), pMouseEvent->getCursorY() ) ;
	}
	
}


/**
 @desc		マウスイベントによる処理を行う条件を満たしているか調べる
 */
bool CUI_Sprite::checkCondition() {
	
	
	
	
	
	return true ;
	
}


/**
 @desc		マウスカーソルが重なった時の処理
 */
void CUI_Sprite::beginOverLap() {}

/**
 @desc		マウスカーソルが離れた時の処理
 */
void CUI_Sprite::endOverLap() {}


// =========================================================
// OverLap判定関連
// =========================================================
/**
 @desc		マウスカーソルが重なっているかどうか調べる
 @param		マウスカーソル座標
 @return	true...重なっている
 */
bool CUI_Sprite::isCursorOverLap( const cocos2d::Point& cursorPos ) {
	
	
	// マウスイベントで得られるマウスカーソル座標は画面左上が原点で
	// 右方向が +X, 下方向が -Yになる
	// なので 得られた Y座標に画面縦幅を加算して画面左下を原点扱いにする
	Point testPos = Point( cursorPos.x, cursorPos.y + WINDOW_TOP ) ;
	
	// 矩形の原点
	Point myOrigin = this->m_rectOriginPos ;
	// 矩形の幅
	Size mySize = Size( this->getContentSize().width * this->getScaleX(), -this->getContentSize().height * this->getScaleY() ) ;
	// 判定を行う矩形を取得
	Rect myRect = Rect( myOrigin, Size( mySize.width + myOrigin.x, mySize.height + myOrigin.y ) ) ;
	
	// 判定
	if ( testPos.x > myRect.origin.x && testPos.x < myRect.size.width ) {
		if ( testPos.y > myRect.size.height && testPos.y < myRect.origin.y )
			return true ;
	}
	
	return false ;
	
}

















