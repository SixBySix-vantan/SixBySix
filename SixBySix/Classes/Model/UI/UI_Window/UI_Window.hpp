//
//  UI_Window.hpp
//  SixBySix
//
//  Created by 辰巳優太 on 2016/07/18.
//
//

#ifndef UI_Window_hpp
#define UI_Window_hpp


// ウィンドウの種類
enum class UI_WindowType {
	Cards,				// カードウィンドウ
	Details,			// 詳細ウィンドウ
	MyStatus,			// 自分のステータスウィンドウ
	OpponentStatus,		// 相手のステータスウィンドウ
};

// ===================================================================================================================
// UIを表示するウィンドウ
//
// カードやステータスなどの複数のUIを取り付けて表示するウィンドウ
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
class CUI_Window : public cocos2d::Layer {
protected:
	// ウィンドウ背景
	cocos2d::Sprite* m_pBackGround = NULL ;
	
};


#endif /* UI_AWindow_hpp */
