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
	CDynamicSingletonTemplate() {}
	// デストラクタ
	virtual ~CDynamicSingletonTemplate() {}
	
	// 共有インスタンス
	static Ty* m_pSharedInstance ;
	
	
public:
	// 共有インスタンスの取得
	static Ty* getInstance() {
		if ( CDynamicSingletonTemplate<Ty>::m_pSharedInstance == NULL ) {
			CDynamicSingletonTemplate<Ty>::m_pSharedInstance = new Ty() ;
		}
		return CDynamicSingletonTemplate<Ty>::m_pSharedInstance ;
	}
	
	// 共有インスタンスの解放
	static void removeInstance() {
		SAFE_DELETE( CDynamicSingletonTemplate<Ty>::m_pSharedInstance ) ;
	}
	
	
private:
	// 代入不可
	void operator = ( const CDynamicSingletonTemplate& object ) {}
	// コピーコンストラクタ不可
	CDynamicSingletonTemplate( const CDynamicSingletonTemplate &object ) {}
	
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
	// デストラクタ
	virtual ~CStaticSingletonTemplate() {}
	
	
public:
	// 共有インスタンスの取得
	static Ty& getInstance() {
		static Ty sharedInstance ;
		return sharedInstance ;
	}
	
private:
	// 代入不可
	void operator = ( const CStaticSingletonTemplate& object ) {}
	// コピーコンストラクタ不可
	CStaticSingletonTemplate( const CStaticSingletonTemplate &object ) {}
	
};









#endif /* SingletonTemplate_hpp */
