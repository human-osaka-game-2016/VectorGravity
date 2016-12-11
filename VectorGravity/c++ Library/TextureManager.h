/**
 * @file	TextureManager.h
 * @breif	テクスチャを管理をしているクラスヘッダ
 * @author	shibata
 */

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <vector>

class Texture;

class TextureManager
{
public:

	TextureManager();
	~TextureManager();

	/**
	* 画像の読み込み
	* @param [in]	index_		どこの配列番号のテクスチャか	(制作側でenum等を使って判断させる)
	* @param  [in]	filepath_	画像ファイルのパス
	*/
	void LoadTexture(int index_, const char* filepath_);

	/**
	* 詳細な画像の読み込み
	* @param [in]	index_		どこの配列番号のテクスチャか	(制作側でenum等を使って判断させる)
	* @param [in]	filepath_	画像ファイルのパス
	* @param [in]	alpha_		画像の透過値		デフォルトは255
	* @param [in]	red_		画像のR値			デフォルトは0
	* @param [in]	green_		画像のG値			デフォルトは0
	* @param [in]	blue_		画像のB値			デフォルトは0
	* @param [in]	istexsize_	2の累乗かどうか	デフォルトはtrue
	*/
	void LoadTextureEX(int index_, const char* filepath_, int alpha_, int red_, int green_, int blue_, bool istexsize_);

	/**
	 * テクスチャデータの情報取得関数
	 * @param [in] index_ ほしいテクスチャデータの配列番号
	 * @return m_pTexture[index_]->GetTextureData()
	 */
	LPDIRECT3DTEXTURE9 GetTextureData(int index_)
	{
		return m_pTexture[index_]->GetTextureData();
	}


private:

	std::vector<Texture*>		m_pTexture;

};

#endif // !TEXTUREMANAGER_H
