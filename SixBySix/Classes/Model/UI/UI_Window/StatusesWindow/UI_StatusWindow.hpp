//
//  UI_StatusWindow.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef UI_StatusWindow_hpp
#define UI_StatusWindow_hpp

#include "UI_Window.hpp"


// ===================================================================================================================
// ステータスウィンドウ
// 両プレイヤーのステータスを表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
class CUI_StatusWindow : public CUI_Window {
private:
    // プレイヤーの情報の参照？
    // CPlayer* m_pReference = NULL ;
    
    // プレイヤー名ラベル
    Label* m_pPlayerNameLabel = NULL ;
    
    // ライフラベル
    Label* m_pLifeLabel = NULL ;
    
    // 特殊効果アイコン
    vector<Sprite*>* m_pEffectIcons = NULL ;
    
    
public:
	// コンストラクタ
	CUI_StatusWindow() ;
	// デストラクタ
	~CUI_StatusWindow() ;
	
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CUI_StatusWindow ) ;
    
};

#endif /* UI_StatusWindow_hpp */
