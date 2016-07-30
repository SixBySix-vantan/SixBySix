//
//  UILayer.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef UILayer_hpp
#define UILayer_hpp


// 前方宣言
enum class UI_WindowType ;
class CUI_Window ;


// ===================================================================================================================
// UIレイヤー
// 各種UIを取り付けてまとめるクラス
//
// マウスの入力情報はこのクラスから各UIへ伝える
// このクラスをCGameMainクラスなどに取り付ける
// ===================================================================================================================
class CUILayer : public Layer {
private:
    // 取り付ける表示エリア群
	std::map<UI_WindowType, CUI_Window*> m_UIWindows ;
	
	
public:
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CUILayer ) ;
	
};


#endif /* UILayer_hpp */
