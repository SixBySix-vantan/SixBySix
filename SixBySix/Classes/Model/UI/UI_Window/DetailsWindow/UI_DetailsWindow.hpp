//
//  UI_DetailsWindow.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef UI_DetailsWindow_hpp
#define UI_DetailsWindow_hpp

#include "UI_Window.hpp"

// ===================================================================================================================
// 詳細ウィンドウ
// 選択中のオブジェクトの詳細を表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
class CUI_DetailsWindow : public CUI_Window {
private:
    // カード画像
    Sprite* m_pCard = NULL ;
    
public:
	// コンストラクタ
	CUI_DetailsWindow() ;
	// デストラクタ
	~CUI_DetailsWindow() ;
	
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CUI_DetailsWindow ) ;
};

#endif /* UI_DetailsWindow_hpp */
