/**
* @file		Character.cpp
* @breif	�L�����N�^�[�̐e�N���X����
* @author	shibata
*/

#include "Character.h"
#include <Texture.h>



Character::Character() :
//m_pTexture(new Texture),
m_pTexture2(new Texture)
{
	//m_pTexture->LoadTexture("Resource/Texture/Total_File1.png");
	m_pTexture2->LoadTexture("Resource/Texture/Total_File2.png");
}

Character::~Character()
{
	//delete m_pTexture;
	delete m_pTexture;
}

void Character::Control()
{

}

void Character::Draw()
{
}