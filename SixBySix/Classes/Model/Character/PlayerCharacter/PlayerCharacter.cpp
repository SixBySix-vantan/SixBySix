//
//  PlayerCharacter.cpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/07/16.
//
//

#include "SixBySix.hpp"

//================================================================================================
//プレイヤーキャラクター
//================================================================================================
//コンストラクタ
CPlayerCharacter::CPlayerCharacter(){
    
}

//デストラクタ
CPlayerCharacter::~CPlayerCharacter(){
    
}

//初期化
bool CPlayerCharacter::init() {
    //基底クラスのinit()を呼び出す
    if( !CBaseCharacter::init() ){
        //失敗ならばfalseを返す
        return false;
    }
    
    
    //================================================================================================
    //ここはあとで工場に移動予定
    //================================================================================================
    this->setTexture( IMAGE_Player_Character );
    
    //ステータスの生成
    this->m_pStatus = new CStatus();
    this->m_pStatus->set( 0, 0, 5 );
    
    //移動データ生成
    this->m_pMove = new CMove();
    this->m_pMove->setPos( Position_Field +cocos2d::Vec2(50,50) );
    
    //アニメーションデータの生成
    this->m_pAnimations = new std::vector<CAnimation*>;
    this->m_pAnimations->push_back( new CChipNotAnimation() );
    (*this->m_pAnimations)[0]->addChipData( new CChip( 0, 0, 100, 100 ) );
    
    //有効フラグ設定
    this->m_activeFlag = true;
    
    return true;
}

//インスタンス生成
CPlayerCharacter *CPlayerCharacter::create(){
    //インスタンス生成
    CPlayerCharacter *pRet = new (std::nothrow) CPlayerCharacter();
    
    //生成成功　かつ　初期化成功　していれば
    if ( pRet && pRet->init() ) {
        //autoreleaseをとりつけて返す
        pRet->autorelease();
        return pRet;
    }
    
    //失敗していれば削除しnullを返す
    SAFE_DELETE( pRet );
    return NULL;
    
}

//押された時のイベント
void CPlayerCharacter::touchBeganEvent( cocos2d::Point pos ){
    CCLOG("押された");
}

//離された時のイベント
void CPlayerCharacter::touchReleaseEvent( cocos2d::Point pos ){
    //離された時のマウス位置に一番近いパネルにキャラを配置させる。
    //パネル完成待ちまでこのまま
    //this->m_pMove->setPos( pos ); //テスト用
    
    //TODO::ここは絶対このままではいかんぞ！！
    //発表用強引モード！！
    cocos2d::Point pos2 = this->m_pMove->getPos() - Position_Field +FieldSize/2;
    
    cocos2d::Point charaPos = cocos2d::Point( floor(pos2.x /100)*100+50 , floor(pos2.y /100 )*100+50  );
    charaPos += Position_Field -FieldSize/2;
    this->m_pMove->setPos( charaPos );
    
    CCLOG("離された");
}

//動かされた時のイベント
void CPlayerCharacter::touchMoveEvent( cocos2d::Point pos ){
    //キャラの位置をマウスに追従させる
    
    //TODO::ここは絶対このままではいかんぞ！！
    //発表用強引モード！！
    //フィールド外に出ないように設定
    if( pos.x < Position_Field.x -FieldSize.x/2 +50 ){
        pos.x = Position_Field.x -FieldSize.x/2 +50;
    }else if( pos.x > Position_Field.x +FieldSize.x/2 -50){
        pos.x = Position_Field.x +FieldSize.x/2 -50;
    }
    
    if( pos.y < Position_Field.y -FieldSize.y/2 +50 ){
        pos.y = Position_Field.y -FieldSize.y/2 +50;
    }else if( pos.y > Position_Field.y +FieldSize.y/2 -50){
        pos.y = Position_Field.y +FieldSize.y/2 -50;
    }
    
    //自身の位置設定
    this->m_pMove->setPos( pos );
    CCLOG("うごくよねー");
    
}

//キャンセル時のイベント
void CPlayerCharacter::touchCancelEvent( cocos2d::Point pos ) {
    CCLOG("ひぇっ...");
}