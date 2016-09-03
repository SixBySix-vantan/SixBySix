//
//  AttackCard.h
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/09.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================
#include "BaseCard.hpp"

//================================================================================================
//攻撃カード
//================================================================================================
class CAttackCard : public CBaseCard{
private:
    //コンストラクタ
    CAttackCard();
    
    //デストラクタ
    ~CAttackCard();
    
    //初期化
    bool init() override;
    
public:
    
    //インスタンス生成
    static CAttackCard *create();
    
private:
    //入場処理
    virtual void onEnter() override;
    
    //退場
    virtual void onExit() override;
    
    //更新処理
    //virtual void update( float deltaTime ) override;
    
public:
    //================================================================================================
    //メンバ変数 + メンバ関数追加
    //================================================================================================
    
    
    //押された時のイベント
    virtual void touchBeganEvent( cocos2d::Point pos ) override;
    
    //離された時のイベント
    virtual void touchReleaseEvent( cocos2d::Point pos ) override;
    
    //動かされた時のイベント
    virtual void touchMoveEvent( cocos2d::Point pos ) override;
    
    //キャンセル時のイベント
    virtual void touchCancelEvent( cocos2d::Point pos ) override;
    
};