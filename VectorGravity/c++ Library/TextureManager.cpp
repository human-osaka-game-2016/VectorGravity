/**
 * file		TextureManager.cpp
 * @breif	テクスチャを管理しているクラス実装内部
 * @author	shibata
 */

#include "TextureManager.h"
#include "Texture.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	for (unsigned int i = 0; i < m_pTexture.size(); i++)
	{
		delete m_pTexture[i];
	}
}

void TextureManager::LoadTexture(int index_, const char* filepath_)
{
	m_pTexture.push_back(new Texture);

	m_pTexture[index_]->LoadTexture(filepath_);
}

void TextureManager::LoadTextureEX(int index_, const char* filepath_, int alpha_, int red_, int green_, int blue_, bool istexsize_)
{
	m_pTexture.push_back(new Texture);

	m_pTexture[index_]->LoadTextureEX(filepath_, alpha_, red_, green_, blue_, istexsize_);

}