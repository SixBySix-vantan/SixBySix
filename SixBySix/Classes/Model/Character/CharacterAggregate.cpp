//
//  CharacterAggregate.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/08/20.
//
//

#include "SixBySix.hpp"

//================================================================================================
//キャラクター集合体(シングルトン)
//================================================================================================
//共有インスタンス
CCharacterAggregate *CCharacterAggregate::m_pManager = NULL;

//コンストラクタ
CCharacterAggregate::CCharacterAggregate(){
    this->m_pCharacters = new std::vector< CBaseCharacter* >;
}

//デストラクタ
CCharacterAggregate::~CCharacterAggregate(){
    SAFE_DELETE( this->m_pCharacters );
}

//共有インスタンスの取得
CCharacterAggregate *CCharacterAggregate::getInstance(){
    if ( CCharacterAggregate::m_pManager == NULL ) {
        CCharacterAggregate::m_pManager = new CCharacterAggregate();
    }
    
    return CCharacterAggregate::m_pManager;
}

//共有インスタンスの破棄
void CCharacterAggregate::removeInstance(){
    SAFE_DELETE( CCharacterAggregate::m_pManager );
}

//キャラクターの集合体の取得
std::vector< CBaseCharacter* > *CCharacterAggregate::get(){
    return this->m_pCharacters;
}

/**
 *  @desc   キャラクター１体の取得
 *  @param  添字番号
 */
CBaseCharacter *CCharacterAggregate::getAt( int index ){
    //最大数以上ならnullを返す
    if ( this->m_pCharacters->size() <= index ) {
        return NULL;
    }
    
    //添字番号で指定し返す
    return (*this->m_pCharacters)[ index ];
}

/**
 *  @desc   キャラクター１体の取得（名前で検索）
 *  @param  キャラクター名
 */
CBaseCharacter *CCharacterAggregate::getAtName( std::string name ){
    
    for ( CBaseCharacter *pChara : (*this->m_pCharacters) ) {
        //キャラクター名が一致していればそのキャラを返す
        if ( pChara->getName() == name) {
            return pChara;
        }
    }
    
    //存在しなければnullを返す
    return NULL;
}

/**
 *  @desc   キャラクター集合体にキャラクターの追加
 *  @param  追加するキャラクター
 */
void CCharacterAggregate::add( CBaseCharacter *pChara ){
    this->m_pCharacters->push_back( pChara );
}

/**
 *  @desc   キャラクター集合体のサイズ取得
 */
int CCharacterAggregate::getSize(){
    return this->m_pCharacters->size();
}
