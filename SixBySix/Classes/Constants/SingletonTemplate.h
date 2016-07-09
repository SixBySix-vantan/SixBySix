//
//  SingletonTemplate.h
//  AutumnFoliage
//
//  Created by 辰巳優太 on 2016/06/30.
//
//

#ifndef SingletonTemplate_h
#define SingletonTemplate_h

//#include "typeinfo.h"
//#include <cxxabi.h>

// =======================================================================================================
// シングルトンクラスのテンプレートクラス
// 動的タイプ
// =======================================================================================================
template <typename Ty>
class CDynamicSingletonTemplate {
protected:
	// コンストラクタ
	CDynamicSingletonTemplate() {
		
		// クラス名の表示
		CCLOG( "Singleton[%s] 生成", typeid( this ).name() ) ;
		
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
		
		// クラス名の表示
		printf( "Singleton[%s] 解放\n", typeid( this ).name() ) ;
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









#endif /* SingletonTemplate_h */
