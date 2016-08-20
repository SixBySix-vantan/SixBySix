//
//  ObjectCharacter.hpp
//  SixBySix
//
//  Created by 後藤　弘哉 on 2016/07/16.
//
//

#pragma once

//===========================================
// 追加のインクルードここから
//===========================================
#include "BaseCharacter.hpp"


//================================================================================================
//オブジェクトクラス
//================================================================================================
class CObjectCharacter : public CBaseCharacter{
private:
    
    // コンストラクタ
    CObjectCharacter();
    
    // デストラクタ
    ~CObjectCharacter();
    
    // 初期化処理
    bool init() override;
    
    // 更新処理
    void update(float deltaTime) override;
    
public:
    
    //押された時のイベント
    void touchBeganEvent( cocos2d::Point pos ) override;
    
    //離された時のイベント
    void touchReleaseEvent( cocos2d::Point pos ) override;
    
    //動かされた時のイベント
    void touchMoveEvent( cocos2d::Point pos ) override;
    
    //キャンセル時のイベント
    void touchCancelEvent( cocos2d::Point pos ) override;

};