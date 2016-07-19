//
//  UI_Deck.hpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/16.
//
//

#ifndef UI_Deck_hpp
#define UI_Deck_hpp

#include "UI_Card.hpp"


// ===================================================================================================================
// デッキ表示
// CCardUI クラスを継承したデッキとその枚数を表示するクラス
// ===================================================================================================================
class CUI_Deck : public CUI_Card {
public:
	CREATE_FUNC( CUI_Deck ) ;
	
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

#endif /* UI_Deck_hpp */
