//
//  Status.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/08.
//
//

//================================================================================================
//追加インクルード
//================================================================================================
#include "Status.hpp"

//================================================================================================
//ステータスクラス
//================================================================================================
//コンストラクタ
CStatus::CStatus(){
}

//引数付きコンストラクタ
CStatus::CStatus( int defaultPlayerAt, int defaultObjectAt, int maxHp ){
    //ステータスに反映
    this->m_defaultPlayerAttack = defaultPlayerAt;
    this->m_playerAttack = defaultPlayerAt;
    this->m_defaultObjectAttack = defaultObjectAt;
    this->m_objectAttack = defaultObjectAt;
    this->m_maxHp = maxHp;
    this->m_hp = maxHp;
    
}

//デストラクタ
CStatus::~CStatus(){
}

//ステータスの設定
void CStatus::set( int defaultPlayerAt, int defaultObjectAt, int maxHp ){
    //ステータスに反映
    this->m_defaultPlayerAttack = defaultPlayerAt;
    this->m_playerAttack = defaultPlayerAt;
    this->m_defaultObjectAttack = defaultObjectAt;
    this->m_objectAttack = defaultObjectAt;
    this->m_maxHp = maxHp;
    this->m_hp = maxHp;
}

//現在のHPの取得
int CStatus::getHp(){
    return this->m_hp;
}

//現在の対プレイヤー攻撃力の取得
int CStatus::getPlayerAttack(){
    return this->m_playerAttack;
}

//現在の対プレイヤー攻撃力の取得
int CStatus::getObjectAttack(){
    return this->m_objectAttack;
}

//HPの足し算
void CStatus::addHp( int recoverPt ){
    this->m_hp += recoverPt;
    
    //現在の体力が最大体力以上　か?
    if ( this->m_hp >= this->m_maxHp) {
        //現在の体力を最大体力にする
        this->m_hp = this->m_maxHp;
    }
}

//HPの引き算
void CStatus::subHp( int attackPt ){
    
    //現在のHPから攻撃力分引く
    this->m_hp -= attackPt;
    
    //体力が0以下 か？
    if( this->m_hp < 0 ){
        //体力を0にする
        this->m_hp = 0;
    }
}

//対キャラクター攻撃力の引き算(バフ)
void CStatus::addPlayerAttack( int pt ){
    this->m_playerAttack = m_defaultPlayerAttack + pt;
}

//対キャラクター攻撃力の引き算(デバフ)
void CStatus::subPlayerAttack( int pt ){
    this->m_playerAttack = m_defaultPlayerAttack - pt;
    
    //攻撃力が0以下　か?
    if( this->m_playerAttack < 0 ){
        //攻撃力を0にする
        this->m_playerAttack = 0;
    }
}

//対キャラクター攻撃力の初期化
void CStatus::resetPlayerAttack(){
    this->m_playerAttack = this->m_defaultPlayerAttack;
}


//対オブジェクト攻撃力の引き算(バフ)
void CStatus::addObjectAttack( int pt ){
    this->m_objectAttack = m_defaultObjectAttack + pt;
}

//対オブジェクト攻撃力の引き算(デバフ)
void CStatus::subObjectAttack( int pt ){
    this->m_objectAttack = m_defaultObjectAttack - pt;
    
    //攻撃力が0以下　か?
    if( this->m_playerAttack < 0 ){
        //攻撃力を0にする
        this->m_playerAttack = 0;
    }
}

//対オブジェクト攻撃力の初期化
void CStatus::resetObjectAttack(){
    this->m_objectAttack = this->m_defaultObjectAttack;
}