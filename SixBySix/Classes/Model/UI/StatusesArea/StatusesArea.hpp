//
//  StatusesArea.hpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#ifndef StatusesArea_hpp
#define StatusesArea_hpp

#include "cocos2d.h"
using namespace cocos2d ;
using namespace std ;


// ===================================================================================================================
// ステータスエリア
// 両プレイヤーのステータスを表示するクラス
// このクラスを CUILayer クラスに取り付ける
// ===================================================================================================================
class CStatusesArea : public Layer {
private:
    // プレイヤーの情報の参照？
    // CPlayer* m_pReference = NULL ;
    
    // エリア背景
    Sprite* m_pBack = NULL ;
    
    // プレイヤー名ラベル
    Label* m_pPlayerNameLabel = NULL ;
    
    // ライフラベル
    Label* m_pLifeLabel = NULL ;
    
    // 特殊効果アイコン
    vector<Sprite*>* m_pEffectIcons = NULL ;
    
    
public:
    // 初期化
    bool init() override ;
    
    CREATE_FUNC( CStatusesArea ) ;
    
};

#endif /* StatusesArea_hpp */
