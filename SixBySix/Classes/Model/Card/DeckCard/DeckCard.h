//
//  DeckCard.h
//  SixBySix
//
//  Created by 宇山翔 on 2016/07/21.
//
//

#ifndef __SixBySix__DeckCard__
#define __SixBySix__DeckCard__

#include <stdio.h>

#endif /* defined(__SixBySix__DeckCard__) */

//デッキクラス
class CDeckCard{
    
    //デッキの名前
    std::string name;
public:
    //コンストラクタ（デッキの名前を受け取る）
    CDeckCard(std::string DeckName)
    {
            name = DeckName;
    }
    
    
};