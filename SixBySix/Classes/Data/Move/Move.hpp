//
//  Move.hpp
//  SixBySix
//
//  Created by 安田一朗太 on 2016/06/08.
//
//

#pragma once

//================================================================================================
//追加インクルード
//================================================================================================

//================================================================================================
//移動クラス (エフェクトとかに使うかな？)
//================================================================================================
class CMove{
public:
    //コンストラクタ
    CMove();
    //デストラクタ
    ~CMove();
    
private:
    //位置データ
    cocos2d::Point m_pos;
    
    //移動速度
    cocos2d::Vec2 m_vel;
    
    //加速度
    cocos2d::Vec2 m_accele;
    
public:
    //移動計算
    void moveBy();
    
    //位置の取得
    cocos2d::Point getPos();
    
    //位置の設定
    void setPos( cocos2d::Point pos　);
    
    
};