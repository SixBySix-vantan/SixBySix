//
//  PListDecoder.cpp
//  
//
//  Created by 辰巳優太 on 2016/07/05.
//
//


#include "SixBySix.hpp"


// ============================================================================================================================
// PropertyListファイル解析クラス
// Singleton
// ============================================================================================================================
/**
 @desc		コンストラクタ
 */
CPListDecoder::CPListDecoder() {
	CCLOG( "生成[ CPListDecoder ]" ) ;
}


/**
 @desc		デストラクタ
 */
CPListDecoder::~CPListDecoder() {
	CCLOG( "解放[ CPListDecoder ]" ) ;
}


/**
 @desc		ルート要素の取得
 @param		解析するPListファイル名
 */
ValueMap CPListDecoder::getRootElement( std::string PListFileName ) {
	
	// 解析済みのPListファイル群から同名ファイルの要素が存在するか調べ
	// 存在しない場合は解析して返す
	// 存在する場合はそれを返す
	if ( this->m_rootElements.find( PListFileName ) == this->m_rootElements.end() ) {
		return this->decode( PListFileName ) ;
	} else {
		return this->m_rootElements[ PListFileName ] ;
	}
	
}


/**
 @desc		解析済みのPListファイル群の削除
 */
void CPListDecoder::clearRootElements() {
	
	this->m_rootElements.clear() ;
	
}


/**
 @desc		PListファイルの解析
 @param		解析するPListファイル名
 */
ValueMap CPListDecoder::decode( string PListFileName ) {
	
	// 解析
	ValueMap rootElement = FileUtils::getInstance()->getValueMapFromFile( PListFileName ) ;
	
	// 解析した要素を解析済みファイル群に追加
	this->m_rootElements[ PListFileName ] = rootElement ;
	
	return rootElement ;
	
}








