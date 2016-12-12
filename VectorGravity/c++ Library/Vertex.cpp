/**
 * @file	Vertex.cpp
 * @breif	頂点情報を決めるクラス実装内部
 * @author	shibata
 */

#include "Vertex.h"
#include "Texture.h"

Vertex::Vertex() : 
m_pD3Device(GraphicsDevice::Instance().GetDevice())
{

}

Vertex::~Vertex()
{

}

void Vertex::SetTextureSize(float width_, float height_, float maxtu_, float maxtv_, float mintu_, float mintv_)
{
	m_textureWidth	= width_;
	m_textureHeight = height_;
	m_textureMaxTu	= maxtu_;
	m_textureMaxTv	= maxtv_;
	m_textureMinTu	= mintu_;
	m_textureMinTv	= mintv_;
}

void Vertex::DrawLeftTop(float posx_, float posy_, Texture* ptexture_)
{
	CUSTOMVERTEX vertex[4] = 
	{
		{			0.0f,			 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMinTu, m_textureMinTv },
		{ m_textureWidth,			 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMaxTu, m_textureMinTv },
		{ m_textureWidth, m_textureHeight, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMaxTu, m_textureMaxTv },
		{			0.0f, m_textureHeight, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMinTu, m_textureMaxTv },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].x += posx_;
		vertex[i].y += posy_;
	}

	m_pD3Device->SetTexture(0, ptexture_->GetTextureData());

	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));

}

void Vertex::DrawCenter(float posx_, float posy_, Texture* ptexture_)
{
	CUSTOMVERTEX vertex[4] = 
	{
		{ -m_textureWidth / 2.0f, -m_textureHeight / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMinTu, m_textureMinTv },
		{  m_textureWidth / 2.0f, -m_textureHeight / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMaxTu, m_textureMinTv },
		{  m_textureWidth / 2.0f,  m_textureHeight / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMaxTu, m_textureMaxTv },
		{ -m_textureWidth / 2.0f,  m_textureHeight / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, m_textureMinTu, m_textureMaxTv },
	};

	for (int i = 0; i < 4; i++)
	{
		vertex[i].x += posx_;
		vertex[i].y += posy_;
	}

	m_pD3Device->SetTexture(0, ptexture_->GetTextureData());

	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));
}