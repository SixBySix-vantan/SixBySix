//
//  PlayerCharacter.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/07/16.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================
#include "BaseCharacter.hpp"

//================================================================================================
//プレイヤーキャラクター
//================================================================================================
class CPlayerCharacter : public CBaseCharacter{
private:
    //コンストラクタ
    CPlayerCharacter();
    
    //デストラクタ
    ~CPlayerCharacter();
    
    //初期化
    bool init() override;
    
public:
    //インスタンス生成
    static CPlayerCharacter *create();
    
    //押された時のイベント
    void touchBeganEvent( cocos2d::Point pos ) override;
    
    //離された時のイベント
    void touchReleaseEvent( cocos2d::Point pos ) override;
    
    //動かされた時のイベント
    void touchMoveEvent( cocos2d::Point pos ) override;
    
    //キャンセル時のイベント
    void touchCancelEvent( cocos2d::Point pos ) override;

};