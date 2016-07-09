//
//  SingletonTemplate.hpp
//  
//
//  Created by 辰巳優太 on 2016/06/30.
//
//

#ifndef SingletonTemplate_hpp
#define SingletonTemplate_hpp

// =======================================================================================================
// シングルトンクラスのテンプレートクラス
// 動的タイプ
//
// 不要になった際に解放が必要
// =======================================================================================================
template <typename Ty>
class CDynamicSingletonTemplate {
protected:
	// コンストラクタ
	CDynamicSingletonTemplate() {
		
	}
	
	// 共有インスタンス
	static Ty* m_pSharedInstance ;
	
	/**
	 @desc		初期化
	 @tips		継承先で必要な初期化はこの関数をオーバーライドして記述する
	 */
	virtual void init() {}
	
	
public:
	// デストラクタ
	virtual ~CDynamicSingletonTemplate() {
		
	}
	
	// 共有インスタンスの取得
	static Ty* getInstance() {
		if ( CDynamicSingletonTemplate<Ty>::m_pSharedInstance == NULL ) {
			CDynamicSingletonTemplate<Ty>::m_pSharedInstance = new Ty() ;
			CDynamicSingletonTemplate<Ty>::m_pSharedInstance->init() ;
		}
		return CDynamicSingletonTemplate<Ty>::m_pSharedInstance ;
	}
	
	// 共有インスタンスの解放
	static void removeInstance() {
		SAFE_DELETE( CDynamicSingletonTemplate<Ty>::m_pSharedInstance ) ;
	}
	
};

// 共有インスタンスの静的変数
template <typename Ty> Ty* CDynamicSingletonTemplate<Ty>::m_pSharedInstance = NULL ;


// =======================================================================================================
// シングルトンクラスのテンプレートクラス
// 静的タイプ
//
// ゲーム中ずっと必要なファイル解析クラスなどに
// 解放不要
// =======================================================================================================
template <typename Ty>
class CStaticSingletonTemplate {
protected:
	// コンストラクタ
	CStaticSingletonTemplate() {}
	
public:
	/**
	 @desc		初期化
	 @tips		継承先で必要な初期化はこの関数をオーバーライドして記述する
	 */
	virtual void init() {}
	
	// 共有インスタンスの取得
	static Ty* getInstance() {
		static Ty sharedInstance ;
		sharedInstance.init() ;
		return &sharedInstance ;
	}
};









#endif /* SingletonTemplate_hpp */
