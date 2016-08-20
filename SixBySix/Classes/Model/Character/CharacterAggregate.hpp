//
//  CharacterAggregate.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/08/20.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================
#include "BaseCharacter.hpp"

//================================================================================================
//キャラクター集合体(シングルトン)
//================================================================================================
class CCharacterAggregate{
private:
    //共有インスタンス
    static CCharacterAggregate *m_pManager;
    
    //コンストラクタ
    CCharacterAggregate();
    
    //デストラクタ
    ~CCharacterAggregate();
public:
    //共有インスタンスの取得
    static CCharacterAggregate *getInstance();
    //共有インスタンスの破棄
    static void removeInstance();
    
private:
    //キャラクターの集合体
    std::vector< CBaseCharacter* > *m_pCharacters = NULL;
    
public:
    //キャラクターの集合体の取得
    std::vector< CBaseCharacter* > *get();
    
    /**
     *  @desc   キャラクター１体の取得
     *  @param  添字番号
     */
    CBaseCharacter *getAt( int index );
    
    /**
     *  @desc   キャラクター１体の取得（名前で検索）
     *  @param  キャラクター名
     */
    CBaseCharacter *getAtName( std::string name );
    
    /**
     *  @desc   キャラクター集合体にキャラクターの追加
     *  @param  追加するキャラクター
     */
    void add( CBaseCharacter *pChara );
    
    /**
     *  @desc   キャラクター集合体のサイズ取得
     */
    int getSize();
    
};