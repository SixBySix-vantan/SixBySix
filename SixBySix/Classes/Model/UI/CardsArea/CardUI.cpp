//
//  CardUI.cpp
//  6x6
//
//  Created by 辰巳優太 on 2016/06/08.
//
//

#include "SixBySix.hpp"


// ===================================================================================================================
// カード表示
// デッキや手札を表示するクラス
// カードをクリックした時に呼ばれる関数はこのクラスに実装する
// このクラスを継承して デッキ、手札、墓地 の表示クラスを作る
// ===================================================================================================================
// 初期化
bool CCardUI::init() {
    // スーパークラスの初期化
    if ( Sprite::init() == false )
        return false ;
    
    
    // タッチイベントの設定
    this->settingTouchEvent() ;
    
    
    return true ;
    
}


/**
 @desc  タッチイベント設定
 */
void CCardUI::settingTouchEvent() {
    /*
    // イベントリスナーの生成
    auto listener = EventListenerTouchOneByOne::create() ;
    
    // タッチした時の処理を設定
    listener->onTouchBegan = CC_CALLBACK_2( this->onTouchBegan, this ) ;
    
    // イベントリスナーを登録
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( listener, this ) ;
    */
}


// ===================================================================================================================
// デッキ表示
// デッキとその枚数を表示するクラス
// このクラスを CCardsArea クラスに取り付ける
// ===================================================================================================================
// 初期化
bool CDeckUI::init() {
    // スーパークラスの初期化
    if ( CCardUI::init() == false )
        return false ;
    
    // テクスチャ
    this->setTexture( IMAGE_UI_Deck ) ;
    
    
    return true ;
    
}


/**
 @desc  タッチされた時の処理
 */
void CDeckUI::onTouchBegan( Touch* pTouch, Event* pEvent ) {
    
    log( "TouchBegan" ) ;
}


// ===================================================================================================================
// 手札表示
// CCardUI クラスを継承した手札を表示するクラス
// ===================================================================================================================
// 初期化
bool CHandUI::init() {
    // スーパークラスの初期化
    if ( CCardUI::init() == false )
        return false ;
    
    // テクスチャ
    this->setTexture( IMAGE_UI_Hand ) ;
    
    // ちょっと透明に
    //this->setOpacity( 180 ) ;
    
    return true ;
    
}


// ===================================================================================================================
// 墓地表示
// CCardUI クラスを継承した墓地とその枚数を表示するクラス
// ===================================================================================================================
// 初期化
bool CCemeteryUI::init() {
    // スーパークラスの初期化
    if ( CCardUI::init() == false )
        return false ;
    
    // テクスチャ
    this->setTexture( IMAGE_UI_Cemetery ) ;
    
    
    
    return true ;
    
}


