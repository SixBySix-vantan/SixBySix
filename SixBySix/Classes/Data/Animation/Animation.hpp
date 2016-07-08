//
//  Animation.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/06.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================
#include "cocos2d.h"

//================================================================================================
//チップデータクラス
//================================================================================================
typedef cocos2d::Rect CChip;

//================================================================================================
//アニメーションクラス
//================================================================================================
class CAnimation{
protected:
    //カウンター
    int m_counter = 0;
    //アニメーション枚数
    int m_number = 0;
    //切り替え間隔
    int m_interval = 0;
    //現在のフレーム数
    int m_currentframe = 0;
    
    //ループするかどうか true...ループする
    bool m_isLoop = false;
    
    //アニメーションが終了したか　true...終了
    bool m_isEnd = false;
    
public:
    //デフォルトコンストラクタ
    CAnimation();
    
    /**
     *  @desc   コンストラクタ
     *  @param  アニメーション枚数
     *  @param  切り替え間隔
     *  @param  ループするか　(デフォルトはfalse)
     */
    CAnimation( int number, int interval, bool isLoop = false );
    
    //デストラクタ
    virtual ~CAnimation();
    
    //現在のフレーム数の取得
    int getCurrentFrame();
    
    //アニメーションが終了したか
    bool getIsEnd();
    
    //カウンターと現在のフレーム数のリセット
    void clear();
    
    /**
     *  @desc   アニメーションの更新処理
     *  @return 表示するフレーム数
     */
    virtual int update();
    
    /**
     *  @desc   チップデータの追加
     *  @param  チップデータ
     */
    virtual void addChipData( CChip* ) = 0;
    
    /**
     *  @param  現在のフレームのチップを取得する
     *  @return 現在のフレームのチップ
     */
    virtual CChip getCurrentChip() = 0;
    
};

//================================================================================================
//チップアニメーションクラス
//  アニメーションする画像が横に並んでいる場合のみに限る
//  アニメーションクラスを元に現在のフレームから切り取るべき画像を取得
//================================================================================================
class CChipAnimation : public CAnimation{
protected:
    //参照するチップデータ
    CChip *m_pChip = NULL;
    
public:
    /**
     *  @desc   コンストラクタ
     *  @param  アニメーション枚数
     *  @param  切り替え間隔
     *  @param  ループするか　(デフォルトはfalse)
     */
    CChipAnimation( int number, int interval, bool isLoop = false );
        
    //デストラクタ
    ~CChipAnimation();
    
    /**
     *  @desc   チップデータの追加
     *  @param  チップデータ
     */
    void addChipData( CChip *pChip ) override;
    
    /**
     *  @param  現在のフレームのチップを取得する
     *  @return 現在のフレームのチップ
     */
    CChip getCurrentChip() override;
    
};

//================================================================================================
//チップノットアニメーションクラス
//  アニメーションしないアニメーションクラス
//================================================================================================
class CChipNotAnimation : public CChipAnimation{
public:
    //コンストラクタ
    CChipNotAnimation();
    //デストラクタ
    ~CChipNotAnimation();
    
    /**
     *  @desc   更新処理は行わなず返す値は必ず1になる
     */
    int update() override;
    
    /**
     *  @desc   現在フレームのチップを取得する
     *  @return 現在フレームのチップ
     */
    CChip getCurrentChip() override;
    
};

//================================================================================================
//チップリストアニメーションクラス
//  画像がバラバラでも対応可能なアニメーションクラス
//================================================================================================
class CChipListAnimation : public CChipAnimation{
protected:
    //アニメーションチップリスト
    std::vector< CChip* > m_chipList;
    
public:
    /**
     *  @desc   コンストラクタ
     *  @param  切り替え間隔
     *  @param  ループするか　(デフォルトはfalse)
     */
    CChipListAnimation( int interval, bool isLoop = false );
    
    //デストラクタ
    ~CChipListAnimation();
    
    /**
     *  @desc   チップデータの追加
     *  @param  チップデータ
     */
    void addChipData( CChip *pChip ) override;
    
    /**
     *  @desc   現在フレームのチップを取得する
     *  @return 現在フレームのチップ
     */
    CChip getCurrentChip() override;
    
};