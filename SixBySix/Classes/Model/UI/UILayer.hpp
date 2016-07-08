//
//  UILayer.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef UILayer_hpp
#define UILayer_hpp


#include "CardsArea.hpp"
#include "DetailsArea.hpp"
#include "StatusesArea.hpp"


// ===================================================================================================================
// UIレイヤー
// 各種UIを取り付けてまとめるクラス
// このクラスを Scene や CGameMainクラスなどに取り付ける
// ===================================================================================================================
class CUILayer : public Layer {
private:
    // カードエリア
    CCardsArea* m_pCardsArea = NULL ;
    
    // カード詳細エリア
    CDetailsArea* m_pDetailsArea = NULL ;
    
    // ステータスエリア
    CStatusesArea* m_pStatusesAreas[2] = { NULL } ;
    
public:
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CUILayer ) ;
    
    
};


#endif /* UILayer_hpp */
