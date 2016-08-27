//
//  CardStatus.h
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/21.
//
//

#pragma once

class CCardStatus {
    //プレイヤーへの攻撃力
    int playerAtk;
    //オブジェクトへの攻撃力
    int objectAtk;
    //バフ
    int buff;
    //デバフ
    int debuff;
    
public:
    //取得
    int getPlayerAtk();
    
    int getObjectAtk();
    
//public:
//    enum CardType{
//        PlayerAtk,
//        ObjectAtk,
//        Place,
//        //カードのカテゴリ数
//        N_CardCategory,
//        
//        A001,
//        A002,
//        A003,
//        A004,
//        A005,
//        A006,
//        A007,
//        A008,
//        A009,
//        A010,
//        
//        S001,
//        S002,
//        S003,
//        S004,
//        S005,
//        S006,
//        S007,
//        S008,
//        S009,
//        S010,
//        S011,
//        S012,
//        S013,
//        S014,
//        S015,
//        //カードの種類数
//        N_CardVariety,
//        //全カード枚数
//        N_CARD,
//    };
};
//Card carddeck[30];