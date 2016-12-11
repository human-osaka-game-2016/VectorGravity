/**
 * @file	Vertex.h
 * @breif	頂点情報を決めるクラスヘッダ
 * @author	shibata
 */

#ifndef VERTEX_H
#define VERTEX_H

#include "GraphicsDevice.h"

struct CUSTOMVERTEX
{
	FLOAT x;		//!< 画面座標のx軸
	FLOAT y;		//!< 画面座標のy軸
	FLOAT z;		//!< 画面座標のz軸
	FLOAT rhw;		//!< 同次座標
	DWORD color;	//!< 色指定
	FLOAT tu;		//!< テクスチャ座標のx軸
	FLOAT tv;		//!< テクスチャ座標のy軸
};

class Texture;

class Vertex
{
public:

	/**
	 * コンストラクタ
	 */
	Vertex();

	/**
	 * デストラクタ
	 */
	~Vertex();

	/**
	 * テクスチャサイズを指定する関数
	 * @param [in] width_	テクスチャの幅
	 * @param [in] height_	テクスチャの高さ
	 * @param [in] maxtu_	テクスチャの最大x座標
	 * @param [in] maxtv_	テクスチャの最大y座標
	 * @param [in] mintu_	テクスチャの最小x座標
	 * @param [in] mintv_	テクスチャの最小y座標
	 */
	void SetTextureSize(float width_, float height_, float maxtu_ = 1.0f, float maxtv_ = 1.0f, float mintu_ = 0.0f, float mintv_ = 0.0f);

	/**
	 * 左上から描画する関数
	 * @param [in] posx_		左上座標のx軸の値
	 * @param [in] posy_		左上座標のy軸の値
	 * @param [in] pTexture_	現在のテクスチャ情報
	 */
	void DrawLeftTop(float posx_, float posy_);

	/**
	 * 中心から描画する関数
	 * @param [in] posx_		中心座標のx軸の値
	 * @param [in] posy_		中心座標のy軸の値
	 * @param [in] pTexture_	現在のテクスチャ情報
	 */
	void DrawCenter(float posx_, float posy_);


private:

	LPDIRECT3DDEVICE9	m_pD3Device;	//!< DirectXのデバイス
	Texture*			m_pTexture;
	float				m_textureWidth;
	float				m_textureHeight;
	float				m_textureMaxTu;
	float				m_textureMaxTv;
	float				m_textureMinTu;
	float				m_textureMinTv;
};


#endif // !VERTEX_H