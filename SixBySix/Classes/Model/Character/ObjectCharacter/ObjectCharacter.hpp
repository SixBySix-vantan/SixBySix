//
//  ObjectCharacter.hpp
//  SixBySix
//
//  Created by 後藤　弘哉 on 2016/07/16.
//
//

#ifndef ObjectCharacter_hpp
#define ObjectCharacter_hpp

#include <stdio.h>

//===========================================
// 追加のインクルードここから
//===========================================
#include "BaseCharacter.hpp"

class CObjectCharacter : public CBaseCharacter{
private:
    
    // コンストラクタ
    CObjectCharacter();
    
    // デストラクタ
    ~CObjectCharacter();
    
    // 初期化処理
    virtual bool init() override;
    
    // 更新処理
    virtual void update(float deltaTime) override;
};


#endif /* ObjectCharacter_hpp */
/*
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
*/