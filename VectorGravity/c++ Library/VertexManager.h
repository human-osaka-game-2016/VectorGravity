/**
 * @file	VertexManaer.h
 * @breif	頂点情報を管理しているクラスヘッダ
 * @author	shibata
 */

#ifndef VERTEXMANAGER_H
#define VERTEXMANAGER_H

#include <d3dx9.h>
#include <vector>

class Vertex;

class VertexManager
{
public:

	VertexManager();
	~VertexManager();

	/**
	* テクスチャサイズを指定する関数
	* @param [in] width_	テクスチャの幅
	* @param [in] height_	テクスチャの高さ
	* @param [in] maxtu_	テクスチャの最大x座標
	* @param [in] maxtv_	テクスチャの最大y座標
	* @param [in] mintu_	テクスチャの最小x座標
	* @param [in] mintv_	テクスチャの最小y座標
	*/
	void SetTextureSize(float width_, float height_, float maxtu_, float maxtv_, float mintu_, float mintv_);

	/**
	* 左上から描画する関数
	* @param [in] posx_		左上座標のx軸の値
	* @param [in] posy_		左上座標のy軸の値
	* @param [in] pTexture_	現在のテクスチャ情報
	*/
	void DrawLeftTop(float posx_, float posy_, LPDIRECT3DTEXTURE9 pTexture_);

	/**
	* 中心から描画する関数
	* @param [in] posx_		中心座標のx軸の値
	* @param [in] posy_		中心座標のy軸の値
	* @param [in] pTexture_	現在のテクスチャ情報
	*/
	void DrawCenter(float posx_, float posy_, LPDIRECT3DTEXTURE9 pTexture_);

private:

	std::vector<Vertex*>	m_pVertex;
};

#endif // !VERTEXMANAGER_H
