/**
* @file		Character.cpp
* @breif	キャラクターの親クラス実装
* @author	shibata
*/

#include "Character.h"
#include <Texture.h>



Character::Character()
{
	m_pTexture->LoadTexture("Resource\Texture\Total_File1.png");
}

Character::~Character()
{

}

void Character::Control()
{

}

void Character::Draw()
{

}