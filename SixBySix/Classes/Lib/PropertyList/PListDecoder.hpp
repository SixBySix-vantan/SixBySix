//
//  PListDecoder.h
//  
//
//  Created by 辰巳優太 on 2016/07/05.
//
//

#ifndef PListDecoder_h
#define PListDecoder_h

#include "SingletonTemplate.h"

using namespace cocos2d ;
using namespace std ;

// ============================================================================================================================
// PropertyListファイル解析クラス
// Singleton
// ============================================================================================================================
class CPListDecoder : public CStaticSingletonTemplate<CPListDecoder> {
private:
	// 解析済みのPListファイル群
	map<string, ValueMap> m_rootElements ;
	
public:
	/**
	 @desc		ルート要素の取得
	 @param		解析するPListファイル名
	 */
	ValueMap getRootElement( string PListFileName ) ;
	
	/**
	 @desc		解析済みのPListファイル群の削除
	 */
	void clearRootElements() ;
	
	
private:
	/**
	 @desc		PListファイルの解析
	 @param		解析するPListファイル名
	 */
	ValueMap decode( string PListFileName ) ;
	
	
};

















#endif /* PListDecoder_h */
