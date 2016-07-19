//
//  Constants.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/05.
//
//

#pragma once

//================================================================================================
//マクロの登録
//================================================================================================
// メモリ解放
#define SAFE_DELETE(p_) if(p_){ delete p_; p_ = NULL; }

//配列のメモリ解放
#define SAFE_DELETE_ARRAY(p_) if(p_){ delte [] p_; p_ = NULL; }

//================================================================================================
//定数登録
//================================================================================================
//画面端
//左
#define WINDOW_LEFT (0)
//右
#define WINDOW_RIGHT (1280)
//上
#define WINDOW_TOP (720)
//下
#define WINDOW_BOTTOM (0)

// 画面中央
#define WINDOW_CENTER       (Vec2( WINDOW_RIGHT * 0.5f, WINDOW_TOP * 0.5f ))


//================================================================================================
//画像の登録
//================================================================================================
#define IMAGE_Field             "field.png"
#define IMAGE_Field600          "field600x600.png"
#define IMAGE_UI_CardsArea      "cardsArea.png"
#define IMAGE_UI_Deck           "deck.png"
#define IMAGE_UI_Hand           "hand.png"
#define IMAGE_UI_Cemetery       "cemetery.png"

#define IMAGE_UI_StatusesArea   "statusesArea.png"

#define IMAGE_UI_DetailsArea    "details.png"

#define IMAGE_UI_Icon_Fire		"Test_Icon_Fire.png"
#define IMAGE_UI_Icon_Ice		"Test_Icon_Ice.png"

//================================================================================================
//音楽登録
//================================================================================================


// ===============================================================================================
// 位置
//================================================================================================
#define Position_Field              (Vec2( WINDOW_RIGHT - 440, WINDOW_TOP - 300 ) )
#define Position_CardsArea          (Vec2( WINDOW_RIGHT * 0.5f, 60.f ) )

#define Position_DetailsArea        (Vec2( WINDOW_RIGHT * 0.5f - 310.f, WINDOW_TOP - 300.f ) )

#define Position_P1_StatusesArea    (Vec2( 60.f, WINDOW_TOP - 300.f ) )
#define Position_P2_StatusesArea    (Vec2( WINDOW_RIGHT - 60.f, WINDOW_TOP - 300.f ) )


//================================================================================================
//その他外部ファイル登録
//================================================================================================