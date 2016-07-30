//
//  UI_Body.hpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/30.
//
//

#ifndef UI_Body_hpp
#define UI_Body_hpp


// ===================================================================================================================
// UIの実体データ
//
// マウスオーバーラップ判定に利用する
// ===================================================================================================================
class CUI_Body {
private:
	// 上
	int m_top ;
	// 下
	int m_bottom ;
	// 左
	int m_left ;
	// 右
	int m_right ;
	
	
public:
	/**
	 @desc		コンストラクタ
	 @param		上
	 @param		下
	 @param		左
	 @param		右
	 */
	CUI_Body( int top, int bottom, int left, int right ) ;
	
	/**
	 @desc		設定
	 @param		上
	 @param		下
	 @param		左
	 @param		右
	 */
	void set( int top, int bottom, int left, int right ) ;
	
	/**
	 @desc		上の取得
	 @return	上
	 */
	int getTop() ;
	
	/**
	 @desc		下の取得
	 @return	下
	 */
	int getBottom() ;
	
	/**
	 @desc		左の取得
	 @return	左
	 */
	int getLeft() ;
	
	/**
	 @desc		右の取得
	 @return	右
	 */
	int getRight() ;
	
};


#endif /* UI_Body_hpp */
