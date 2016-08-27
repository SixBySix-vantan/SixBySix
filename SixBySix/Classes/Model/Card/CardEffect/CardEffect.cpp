//
//  CardEffect.cpp
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/09.
//
//

#include "SixBySix.hpp"

//================================================================================================
//カード効果基底クラス
//================================================================================================
CCardEffect::~CCardEffect(){}

//================================================================================================
//敵プレイヤーへの攻撃
//================================================================================================
/**
 @desc      コンストラクタ
 @param     効果のステータス
 */
CPlayerAttackEffect::CPlayerAttackEffect( CCardStatus* pStatus ) {
    this->m_Status = pStatus ;
}



void CPlayerAttackEffect::runEffect( CStatus *pStatus ){
    
    //HPを減少させる
    pStatus->subHp( m_Status->getPlayerAtk() );
    
    //HPが0以下だった場合の有効フラグを下げる
    //ここはプレイヤーの部分で処理でいいと思います
    //        if( m_Status->getHp()<=0 ){
    //            this->m_activeFlag = false;
    //        }
}
//================================================================================================
//オブジェクトへの攻撃
//================================================================================================


//================================================================================================
//効果範囲
//================================================================================================

//================================================================================================
//オブジェクト設置
//================================================================================================

//================================================================================================
//パネル移動
//================================================================================================

//================================================================================================
//バフ
//================================================================================================

/**
 @desc      コンストラクタ
 @param     効果のステータス
 */
CBuffEffect::CBuffEffect( CCardStatus* pStatus ) {
    this->m_Status = pStatus ;
}

void CBuffEffect::runEffect( CStatus *pStatus ){
    //攻撃力の増加
    pStatus->addPlayerAttack( m_Status->getPlayerAtk());
}

//================================================================================================
//デバフ
//================================================================================================
/**
 @desc      コンストラクタ
 @param     効果のステータス
 */
CDeBuffEffect::CDeBuffEffect( CCardStatus* pStatus ) {
    this->m_Status = pStatus ;
}

void CDeBuffEffect::runEffect( CStatus *pStatus ){
    //攻撃力の減少
    pStatus->subPlayerAttack( m_Status->getPlayerAtk());
}

//================================================================================================
//ドロー
//================================================================================================
