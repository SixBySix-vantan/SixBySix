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
    bool touchBeganEvent() override;
    
    //離された時のイベント
    void touchReleaseEvent() override;
    
    //動かされた時のイベント
    void touchMoveEvent() override;
    
    //キャンセル時のイベント
    void touchCancelEvent() override;

};