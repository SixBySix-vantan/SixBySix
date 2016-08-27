//
//  HandCard.h
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/09.
//
//

#pragma once 

#include "BaseCard.hpp"
#include "cocos2d.h"


using namespace cocos2d;

class HandCard : public cocos2d::Layer
{
private:
    // 画面サイズ
    Size visibleSize;
    
    // スプライト
    cocos2d::Sprite* sprite;
    
public:
    // C++にはIDがないので、クラスのインスタンスポインタを返すことを推奨する。
    static Scene* createScene();
    
    // initメソッドは、cocos2d-iphoneではIDを返すが、cocos2d-xではboolを返すという違いがある。
    virtual bool init();
    // a selector callback
    // セレクタのコースバック
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // static create()関数のマニュアル実装
    CREATE_FUNC(HandCard);
    
    // 次の位置を取得する。
    Point* getNextPosition();
};