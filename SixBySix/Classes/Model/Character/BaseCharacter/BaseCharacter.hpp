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
    virtual bool init() override;
    
    // 反映処理
    //virtual void applyFunc();
    
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
    std::vector<CAnimation*>* m_pAnimations = NULL;
    
    //ステータス
    CStatus *m_pStatus = NULL;
    
    //位置情報
    CMove *m_pMove = NULL;
    
    //生存フラグ
    bool m_isAlive = false;
    
    // 有効フラグ
    bool m_activeFlag = false;
    
    //状態
    int m_state = 0;
    
    //反映処理
    virtual void applyFunc();
    
    //状態確認
    virtual void checkState();
    
    //押された時のイベント
    virtual void touchBeganEvent( cocos2d::Point pos ) = 0;
    
    //離された時のイベント
    virtual void touchReleaseEvent( cocos2d::Point pos ) = 0;
    
    //動かされた時のイベント
    virtual void touchMoveEvent( cocos2d::Point pos ) = 0;
    
    //キャンセル時のイベント
    virtual void touchCancelEvent( cocos2d::Point pos ) = 0;
};