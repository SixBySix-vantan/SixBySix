//
//  UI_Cemetery.hpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/16.
//
//

#ifndef UI_Cemetery_hpp
#define UI_Cemetery_hpp

#include "UI_Card.hpp"


// ===================================================================================================================
// 墓地表示
// CCardUI クラスを継承した墓地とその枚数を表示するクラス
// ===================================================================================================================
class CUI_Cemetery : public CUI_Card {
public:
	CREATE_FUNC( CUI_Cemetery ) ;
	
	// 初期化
	bool init() override ;
	
	
	// =========================================================
	// マウスイベント関連
	// =========================================================
protected:
	/**
	 @desc		マウスカーソルが重なった時の処理
	 */
	void beginOverLap() override ;
	
	/**
	 @desc		マウスカーソルが離れた時の処理
	 */
	void endOverLap() override ;
	
};

#endif /* UI_Cemetery_hpp */
