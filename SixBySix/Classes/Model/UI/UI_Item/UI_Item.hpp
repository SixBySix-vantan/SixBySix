//
//  UI_Item.hpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/16.
//
//

#ifndef UI_Item_hpp
#define UI_Item_hpp


// ===================================================================================================================
// UIアイテム
// UI一つそのもの
//
// スプライトのUI
// 入力による挙動は継承先で定義する
// ===================================================================================================================
class CUI_Sprite : public cocos2d::Sprite {
public:
	// 初期化
	bool init() override ;
	
	/**
	 @desc		入場処理
	 */
	void onEnter() override ;
	
	/**
	 @desc		退場処理
	 */
	void onExit() override ;
	
	/**
	 @desc		絶対座標の設定
	 */
	void setAbsPosition() ;
	
	/**
	 @desc		絶対座標の取得
	 @return	絶対座標
	 */
	cocos2d::Point getAbsPosition() ;
	
	
protected:
	/**
	 @desc		OverLap判定を行う矩形の原点の設定
	 @tips		絶対座標を設定後に呼び出される
	 */
	void setRectOriginPosition() ;
	
	
	// =========================================================
	// マウスイベント関連
	// =========================================================
public:
	/**
	 @desc		マウス入力イベントの受け付け設定
	 */
	void setMouseEvent() ;
	
	/**
	 @desc		マウスを動かした際のイベント
	 @param		マウスイベント
	 */
	void onMouseMove( EventMouse* ) ;
	
	/**
	 @desc		マウスを左クリックした際のイベント
	 @param		マウスイベント
	 */
	void onMouseDown( EventMouse* ) ;
	
	
protected:
	// 画面左下からの絶対座標
	cocos2d::Vec2 m_absPosition ;
	
	// マウスカーソルが重なっているかどうかのフラグ
	bool m_isOverLap = false ;
	
	/**
	 @desc		マウスイベントによる処理を行う条件を満たしているか調べる
	 */
	bool checkCondition() ;
	
	/**
	 @desc		マウスカーソルが重なった時の処理
	 */
	virtual void beginOverLap() ;
	
	/**
	 @desc		マウスカーソルが離れた時の処理
	 */
	virtual void endOverLap() ;
	
	
	// =========================================================
	// OverLap判定関連
	// =========================================================
	// OverLap判定を行う矩形の原点
	Point m_rectOriginPos ;
	
	/**
	 @desc		マウスカーソルが重なっているかどうか調べる
	 @param		マウスカーソル座標
	 @return	true...重なっている
	 */
	bool isCursorOverLap( const cocos2d::Point& cursorPos ) ;
	
};




#endif /* UI_Item_hpp */
