//
//  CardStatus.cpp
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/21.
//
//

#include "SixBySix.hpp"

//デフォルタコンストラクタ
CCardStatus::CCardStatus(){
    
}

/**
 *  @desc   引数付きコンストラクタ
 *  @param  プレイヤー攻撃力
 *  @param  オブジェクト攻撃力
 */
CCardStatus::CCardStatus( int playerAtk, int objectAtk ) : m_playerAtk( playerAtk ), m_objectAtk( objectAtk ){
    
}

//プレイヤー攻撃力の取得
int CCardStatus::getPlayerAtk(){
    return m_playerAtk;
}

//オブジェクト攻撃力の取得
int CCardStatus::getObjectAtk(){
    return m_objectAtk;
}
