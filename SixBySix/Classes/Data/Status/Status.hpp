//
//  Status.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/08.
//
//



#pragma once
//================================================================================================
//追加インクルード
//================================================================================================

//================================================================================================
//ステータスクラス
//================================================================================================
class CStatus{
public:
    //コンストラクタ
    CStatus();
    //引数付きコンストラクタ
    CStatus( int defaultPlayerAt, int defaultObjectAt, int maxHp );
    
    //デストラクタ
    ~CStatus();
    
private:
    //対キャラクター攻撃力:初期値
    int m_defaultPlayerAttack;
    
    //対オブジェクト攻撃力:初期値
    int m_defaultObjectAttack;
    
    //最大体力
    int m_maxHp;
    
    //移動力
    //TODO:レンジできてから実装(enumで管理予定)

public:
    //対キャラクター攻撃力
    int m_playerAttack;
    
    //対オブジェクト攻撃力
    int m_objectAttack;
    
    //現在の体力
    int m_hp;
    
public:
    //ステータスの設定
    void set( int defaultPlayerAt, int defaultObjectAt, int maxHp );
    
    //HPの加算
    void addHp( int recoverPt );

    //HPの減算
    void subHp( int attackPt );
    
    //対キャラクター攻撃力の加算(バフ)
    void addPlayerAttack( int pt );
    
    //対キャラクター攻撃力の減算(デバフ)
    void subPlayerAttack( int pt );
    
    //対キャラクター攻撃力の初期化
    void resetPlayerAttack();
    
    //対オブジェクト攻撃力の加算(バフ)
    void addObjectAttack( int pt );
    
    //対オブジェクト攻撃力の減算(デバフ)
    void subObjectAttack( int pt );
    
    //対オブジェクト攻撃力の初期化
    void resetObjectAttack();
};