//
//  Animation.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/06.
//
//

#include "Animation.hpp"
#include "Constants.hpp"

//================================================================================================
//アニメーションクラス
//================================================================================================

//デフォルトコンストラクタ
CAnimation::CAnimation(){}

/**
 *  @desc   コンストラクタ
 *  @param  アニメーション枚数
 *  @param  切り替え間隔
 *  @param  ループするか　(デフォルトはfalse)
 */
CAnimation::CAnimation( int number, int interval, bool isLoop ) : m_number( number ), m_interval( interval ), m_isLoop( isLoop ){}

//デストラクタ
CAnimation::~CAnimation(){}

//現在のフレーム数の取得
int CAnimation::getCurrentFrame(){
    return this->m_currentframe;
}

//アニメーションが終了したか
bool CAnimation::getIsEnd(){
    return this->m_isEnd;
}

//カウンターと現在のフレーム数のリセット
void CAnimation::clear(){
    this->m_counter = 0;
    this->m_currentframe = 0;
}

/**
 *  @desc   アニメーションの更新処理
 *  @return 表示するフレーム数
 */
int CAnimation::update(){
    
    //アニメーションが終了していなければカウンターの更新
    if ( this->m_isEnd == false ) {
        this->m_counter++;
        
        //カウンタの数値 が (切り替え間隔*アニメーション枚数) 以上になったら
        if ( this->m_counter >= this->m_interval * this->m_number ) {
            if ( this->m_isLoop == true ) {
                //ループする場合は
                
                //カウンタをリセット
                this->m_counter = 0;
                
            }else{
                //ループしない場合は
                
                //アニメーション終了フラグをtrueにする
                this->m_isEnd = true;
                //カウンタがはみ出た分をデクリメント
                this->m_counter--;
            }
        }
    }
    
    //表示するフレーム( int型のため小数点以下は切り捨てられる )
    this->m_currentframe = this->m_counter / this->m_interval;
    
    return this->m_currentframe;
}

//================================================================================================
//チップアニメーションクラス
//  アニメーションする画像が横に並んでいる場合のみに限る
//  アニメーションクラスを元に現在のフレームから切り取るべき画像を取得
//================================================================================================
/**
 *  @desc   コンストラクタ
 *  @param  アニメーション枚数
 *  @param  切り替え間隔
 *  @param  ループするか　(デフォルトはfalse)
 */
CChipAnimation::CChipAnimation( int number, int interval, bool isLoop ) : CAnimation( number, interval, isLoop ){
    
}

//デストラクタ
CChipAnimation::~CChipAnimation(){
    
}

/**
 *  @desc   チップデータの追加
 *  @param  チップデータ
 */
void CChipAnimation::addChipData( CChip *pChip){
    this->m_pChip = pChip;
    
}

/**
 *  @param  現在のフレームのチップを取得する
 *  @return 現在のフレームのチップ
 */
CChip CChipAnimation::getCurrentChip(){
    CChip chip(
               this->m_pChip->size.width * this->m_currentframe,
               this->m_pChip->origin.y,
               this->m_pChip->size.width,
               this->m_pChip->size.height );
    return chip;
    
}

//================================================================================================
//チップノットアニメーションクラス
//  アニメーションしないアニメーションクラス
//================================================================================================
//コンストラクタ
CChipNotAnimation::CChipNotAnimation() : CChipAnimation( 0, 0, false ){
}

//デストラクタ
CChipNotAnimation::~CChipNotAnimation(){
}

/**
 *  @desc   更新処理は行わなず返す値は必ず1になる
 */
int CChipNotAnimation::update(){
    return 1;
}

/**
 *  @desc   現在フレームのチップを取得する
 *  @return 現在フレームのチップ
 */
CChip CChipNotAnimation::getCurrentChip(){
    return *this->m_pChip;
}

//================================================================================================
//チップリストアニメーションクラス
//  画像がバラバラでも対応可能なアニメーションクラス
//================================================================================================
/**
 *  @desc   コンストラクタ
 *  @param  切り替え間隔
 *  @param  ループするか　(デフォルトはfalse)
 */
CChipListAnimation::CChipListAnimation( int interval, bool isLoop ) : CChipAnimation( 0, interval, isLoop ){
    
}

//デストラクタ
CChipListAnimation::~CChipListAnimation(){
    
    //要素の中身を削除する
    std::vector< CChip* >::iterator itr = this->m_chipList.begin();
    while ( itr != this->m_chipList.end() ) {
        SAFE_DELETE( *itr );
        itr++;
    }
}

/**
 *  @desc   チップデータの追加
 *  @param  チップデータ
 */
void CChipListAnimation::addChipData( CChip *pChip ){
    
    //チップデータの追加
    this->m_chipList.push_back( pChip );
    
    //アニメーションの最大数も更新させる
    this->m_number = this->m_chipList.size();
    
}

/**
 *  @desc   現在フレームのチップを取得する
 *  @return 現在フレームのチップ
 */
CChip CChipListAnimation::getCurrentChip(){
    //添字演算子で中身を返す
    return *(this->m_chipList[ this->m_currentframe ]);
}