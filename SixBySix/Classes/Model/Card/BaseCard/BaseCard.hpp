//
//  BaseCard.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/11.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================
#include "CardEffect.h"

//================================================================================================
//基底カードクラス
//================================================================================================
class CBaseCard : public cocos2d::Sprite{
protected:
    //コンストラクタ
    CBaseCard();
    
    //デストラクタ
    ~CBaseCard();
    
    //初期化
    bool init() override;
    
public:
    
    //インスタンス生成
    //static CBaseCard *create();
    
private:
    //入場処理
    virtual void onEnter() override;
    
    //退場
    virtual void onExit() override;
    
    //更新処理
    virtual void update( float deltaTime ) override;
    
public:
    //================================================================================================
    //メンバ変数 + メンバ関数追加
    //================================================================================================
    //カードステータス
    CCardStatus *m_pCardStatus = NULL;
    
    //カード効果
    std::vector<CCardEffect*> *m_pCardEffect = NULL;
    
    //押された時のイベント
    virtual void touchBeganEvent( cocos2d::Point pos ) = 0;
    
    //離された時のイベント
    virtual void touchReleaseEvent( cocos2d::Point pos ) = 0;
    
    //動かされた時のイベント
    virtual void touchMoveEvent( cocos2d::Point pos ) = 0;
    
    //キャンセル時のイベント
    virtual void touchCancelEvent( cocos2d::Point pos ) = 0;
};