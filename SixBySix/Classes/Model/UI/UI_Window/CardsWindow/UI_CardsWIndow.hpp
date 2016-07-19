//
//  UI_CardsWindow.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef UI_CardsWindow_hpp
#define UI_CardsWindow_hpp

#include "UI_Window.hpp"

// 前方宣言
class CUI_Card ;


// ===================================================================================================================
// カードウィンドウ
// デッキ・手札・墓地のカードを取り付けて表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
class CUI_CardsWindow : public CUI_Window {
private:
    // デッキ画像
    CUI_Card* m_pDeck = NULL ;
	
    // 手札画像群
	std::vector<CUI_Card*> m_hands ;
    
    // 墓地画像
    CUI_Card* m_pCemetery = NULL ;
    
    
public:
	// コンストラクタ
	CUI_CardsWindow() ;
    // デストラクタ
    ~CUI_CardsWindow() ;
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CUI_CardsWindow ) ;
    
};


#endif /* UI_CardsWindow_hpp */
