//
//  BaseCharacter.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/11.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================
#include "Status.hpp"
#include "Animation.hpp"
#include "Move.hpp"

//================================================================================================
//基底キャラクタークラス
//================================================================================================
class CBaseCharacter : public cocos2d::Sprite{
protected:
    //コンストラクタ
    CBaseCharacter();
    
    //デストラクタ
    ~CBaseCharacter();
    
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
    //アニメーションデータ
    CAnimation *m_pAnimation = NULL;
    
    //ステータス
    CStatus *m_pStatus = NULL;
    
    //位置情報
    CMove *m_pMove = NULL;
    
    //押された時のイベント
    virtual bool touchBeganEvent() = 0;
    
    //離された時のイベント
    virtual void touchReleaseEvent() = 0;
    
    //動かされた時のイベント
    virtual void touchMoveEvent() = 0;
    
    //キャンセル時のイベント
    virtual void touchCancelEvent() = 0;
};