//
//  Phase.hpp
//  SixBySix
//
//  Created by 岡本幸二 on 2016/07/09.
//
//

#pragma once

#define IMAGE_START "StartPhaes.png"
#define IMAGE_MAIN "MainPhaes.png"
#define IMAGE_END "EndPhaes.png"
#define IMAGE_BATTLE "BattlePhaes.png"

//================================================================================================
// フェイズタイプ
//================================================================================================
enum class PHAES_TYPE : int{
    START = 0,
    MAIN = 1,
    END = 2,
    BATTLE = 3,
    
    MAX,    //4
};

//================================================================================================
//基底フェイズクラス
//================================================================================================
class CPhaes{
public:
    //フェイズ切り替え時に呼ばれる関数
    virtual void start() = 0;
    
    //更新処理
    virtual void update() = 0;
    
    //フェイズ終了時に呼ばれる関数
    virtual void end() = 0;
};

//================================================================================================
//スタートフェイズ
//================================================================================================
class CStartPhaes : public CPhaes{
public:
    //フェイズ切り替え時に呼ばれる関数
    void start()override;
    
    //更新処理
    void update()override;
    
    //フェイズ終了時に呼ばれる関数
    void end()override;
};

//================================================================================================
//メインフェイズ
//================================================================================================
class CMainPhaes : public CPhaes{
public:
    //フェイズ切り替え時に呼ばれる関数
    void start()override;
    
    //更新処理
    void update()override;
    
    //フェイズ終了時に呼ばれる関数
    void end()override;
};

//================================================================================================
//バトルフェイズ
//================================================================================================
class CBattlePhaes : public CPhaes{
public:
    //フェイズ切り替え時に呼ばれる関数
    void start()override;
    
    //更新処理
    void update()override;
    
    //フェイズ終了時に呼ばれる関数
    void end()override;
};

//================================================================================================
//エンドフェイズ
//================================================================================================
class CEndPhaes : public CPhaes{
public:
    //フェイズ切り替え時に呼ばれる関数
    void start()override;
    
    //更新処理
    void update()override;
    
    //フェイズ終了時に呼ばれる関数
    void end()override;
};

    
//================================================================================================
//フェイズラベル
//================================================================================================
class CPhaesSprite : public cocos2d::Sprite{
public:
    CPhaesSprite(){
        
    };
    
    //自作生成関数
    static CPhaesSprite* create(PHAES_TYPE type){
        CPhaesSprite* pRef = new CPhaesSprite();
        pRef->init( type );
        pRef->autorelease();
        return pRef;
    };
    
    /**
     * @desc    初期化処理
     * @desc    フェイズタイプ
     */
    bool init(PHAES_TYPE type){
        if(!cocos2d::Sprite::init())return false;
        
        this->setTexture( this->m_phaesImageName[(int)type].c_str() );
        this->setOpacity(0);
        
        
        
        return true;
    }
    
    std::string m_phaesImageName[(int)PHAES_TYPE::MAX] = {
        IMAGE_START,
        IMAGE_MAIN,
        IMAGE_END,
        IMAGE_BATTLE,
    };
};

//================================================================================================
//フェイズシングルトン
//================================================================================================
class CPhaesManager {
private:
    //コンストラクタ
    CPhaesManager(){
        
        //集まりにフェイズを設定
        m_pPhaesArray[(int)PHAES_TYPE::START] = new CStartPhaes;
        m_pPhaesArray[(int)PHAES_TYPE::MAIN] = new CMainPhaes;
        m_pPhaesArray[(int)PHAES_TYPE::BATTLE] = new CBattlePhaes;
        m_pPhaesArray[(int)PHAES_TYPE::END] = new CEndPhaes;
        
    }
    
    //インスタンス
    static CPhaesManager *m_pManager;
    
    //現在のフェイズ
    PHAES_TYPE m_phaesType { PHAES_TYPE::START };
    
    //フェイズの集まり
    CPhaes* m_pPhaesArray[(int)PHAES_TYPE::MAX];
    
public:
    
    //インスタンス取得
    static CPhaesManager *getInstance(){
        if( CPhaesManager::m_pManager == NULL ){
            CPhaesManager::m_pManager = new CPhaesManager();
        }
        
        return m_pManager;
    }
    
    //削除
    static void removeInstance(){
        
        SAFE_DELETE( m_pManager );
    }
    
    //現在のフェイズの取得
    CPhaes* getPhaes(){
        return this->m_pPhaesArray[(int)this->m_phaesType];
    }
    
    //次のフェイズに移動する
    void nextPhaes(cocos2d::Layer* pLayer){
        
        //現在のフェイズのend()を呼び出す
        this->m_pPhaesArray[(int)this->m_phaesType]->end();
        
        //バトルフェイズだったら
        if(this->m_phaesType == PHAES_TYPE::BATTLE){
            this->m_phaesType = PHAES_TYPE::END;
            
            //変更後のstate()を呼び出す
            this->m_pPhaesArray[(int)this->m_phaesType]->start();
            
            return ;
        }
        
        if( (int)this->m_phaesType < (int)PHAES_TYPE::END ){
            
            //タイプを次のタイプに変える
            int type = (int)this->m_phaesType;
            this->m_phaesType = (PHAES_TYPE)++type;
            
        }else{
            
            //タイプがENDならスタートに戻す
            this->m_phaesType = PHAES_TYPE::START;
        }
        
        //変更後のstate()を呼び出す
        this->m_pPhaesArray[(int)this->m_phaesType]->start();
        
        //フェイズのタイプを表示する
        cocos2d::Sprite* pSprite { CPhaesSprite::create(this->m_phaesType) };
        pSprite->setPosition(WINDOW_RIGHT + pSprite->getContentSize().width/2,WINDOW_TOP/2);
        
        auto inmove { cocos2d::MoveTo::create( 0.6f, cocos2d::Vec2( WINDOW_RIGHT * 0.5f, WINDOW_TOP * 0.5f ) ) };
        auto infade { cocos2d::FadeIn::create( 0.6f ) };
        auto inspan { cocos2d::Spawn::create( inmove, infade, NULL ) };
        
        auto delay { cocos2d::DelayTime::create(2.0f) };
        
        auto outmove { cocos2d::MoveTo::create( 0.6f, cocos2d::Vec2( WINDOW_LEFT - pSprite->getContentSize().width/2, WINDOW_TOP * 0.5f ) ) };
        auto outfade { cocos2d::FadeOut::create( 0.6f ) };
        auto outspan { cocos2d::Spawn::create( outmove, outfade, NULL ) };
        
        auto remove { cocos2d::RemoveSelf::create(true) };

        
        auto seq { cocos2d::Sequence::create( inspan, delay, outspan, remove, NULL ) };
        
        pSprite->runAction(seq);
        
        pLayer->addChild(pSprite);
        
        
    }
    
    //次のフェイズをバトルフェイズに変更
    void changeToBattlePhase(){ this->m_phaesType = PHAES_TYPE::BATTLE; }

};






