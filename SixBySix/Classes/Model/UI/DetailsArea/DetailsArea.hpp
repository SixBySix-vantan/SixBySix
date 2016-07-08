//
//  DetailsArea.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef DetailsArea_hpp
#define DetailsArea_hpp

#include "cocos2d.h"
using namespace cocos2d ;
using namespace std ;


// ===================================================================================================================
// 詳細エリア
// 選択中のオブジェクトの詳細を表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
class CDetailsArea : public Layer {
private:
    // カード画像？
    Sprite* m_pCard = NULL ;
    
public:
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CDetailsArea ) ;
};

#endif /* DetailsArea_hpp */
