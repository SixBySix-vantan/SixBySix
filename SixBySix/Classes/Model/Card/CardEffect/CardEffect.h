//
//  CardEffect.h
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/09.
//
//

#ifndef __SixBySix__CardEffect__
#define __SixBySix__CardEffect__

#include <stdio.h>
#include "Status.hpp"

class CCardEffect{
public:
    ~CCardEffect();
    
    //カードの効果発動
    virtual void runEffect() = 0 ;
    
    //有効フラグ
    bool m_activeFlag;
};


//敵プレイヤーへの攻撃
class PlayerAttack : public CCardEffect {
private:
    //ステータス
    CStatus* m_Status = NULL ;
    
public:
    /**
     @desc      コンストラクタ
     @param     効果のステータス
     */
    PlayerAttack( CStatus* pStatus ) {
        this->m_Status = pStatus ;
    }
    
    
    
    void runEffect() override {
        
        //HPを減少させる
        m_Status->subHp( m_Status->getAttackpt() );
        
        //HPが0以下だった場合の有効フラグを下げる
        if( m_Status->getHp()<=0 ){
            this->m_activeFlag = false;
        }
    }
};

//オブジェクトへの攻撃
class ObjectAttack : public CCardEffect {};

//効果範囲
class EffectRange : public CCardEffect {};

//オブジェクト設置
class SettingObject : public CCardEffect {};

//パネル移動
class PanelMove : public CCardEffect {};

//バフ
class Buff : public CCardEffect {
private:
    //ステータス
    CStatus* m_Status = NULL;
    
public:
    /**
     @desc      コンストラクタ
     @param     効果のステータス
     */
    Buff( CStatus* pStatus ) {
        this->m_Status = pStatus ;
    }

    void runEffect() override {
        //攻撃力の増加
        m_Status->addPlayerAttack( m_Status->getAttackpt());
    }
};

//デバフ
class DeBuff : public CCardEffect {
private:
    //ステータス
    CStatus* m_Status = NULL;
    
public:
    /**
     @desc      コンストラクタ
     @param     効果のステータス
     */
    DeBuff( CStatus* pStatus ) {
        this->m_Status = pStatus ;
    }

    void runEffect() override {
        //ステータス
        CStatus* m_Status;
        
        //攻撃力の減少
        m_Status->subPlayerAttack( m_Status->getAttackpt());
    }
};

//ドロー
class Draw : public CCardEffect {};





#endif /* defined(__SixBySix__CardEffect__) */
