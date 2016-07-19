//
//  CardsArea.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef CardsArea_hpp
#define CardsArea_hpp

#include "cocos2d.h"
using namespace cocos2d ;
using namespace std ;

#include "CardUI.hpp"


// ===================================================================================================================
// カードエリア
// デッキ・手札・墓地のカードを取り付けて表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
class CCardsArea : public Layer {
private:
    // エリア背景
    Sprite* m_pBackGround = NULL ;
    
    
    // デッキ画像
    CDeckUI* m_pDeck = NULL ;
    
    
    // 手札画像
    vector<CHandUI*>* m_pHands = NULL ;
    
    
    // 墓地画像
    CCemeteryUI* m_pCemetery = NULL ;
    
    
public:
    // デストラクタ
    ~CCardsArea() ;
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CCardsArea ) ;
    
};


#endif /* CardsArea_hpp */
