//
//  SixBySix.h
//  SixBySix
//
//  Created by 安田一朗太 on 2016/07/09.
//
//

#pragma once

//====================================================================================================================
//全てのヘッダファイルをインクルードするヘッダー
//  実行ファイルではこのヘッダーをインクルードする
//  新しくファイルを作成したら忘れずにこちらにインクルードしておく
//====================================================================================================================
#include "Constants.hpp"


// ===================================================================================================================
// Lib
//
// ===================================================================================================================
#include "PListDecoder.hpp"





// ===================================================================================================================
// Data
//
// ===================================================================================================================
#include "Animation.hpp"
#include "Move.hpp"
#include "Status.hpp"





// ===================================================================================================================
// Model
//
// ===================================================================================================================
// =========================================================
// Card
// =========================================================
#include "BaseCard.hpp"

// =========================================================
// Character
// =========================================================
#include "CharacterAggregate.hpp"
#include "BaseCharacter.hpp"
#include "PlayerCharacter.hpp"
#include "ObjectCharacter.hpp"

// =========================================================
// Field / Panel
// =========================================================
#include "Panel.hpp"
#include "Field.hpp"

// =========================================================
// UI
// =========================================================
#include "UILayer.hpp"
// UI_Window
#include "UI_WIndow.hpp"
#include "UI_CardsWindow.hpp"
#include "UI_StatusWindow.hpp"
#include "UI_DetailsWindow.hpp"
// UI_Item
#include "UI_Item.hpp"
#include "UI_Card.hpp"
#include "UI_Deck.hpp"
#include "UI_Hand.hpp"
#include "UI_Cemetery.hpp"
#include "UI_Body.hpp"





// ===================================================================================================================
// Scene
//
// ===================================================================================================================
#include "GameMain.hpp"

























