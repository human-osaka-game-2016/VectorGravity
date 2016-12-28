/**
 * @file	Player.cpp
 * @breif	プレイヤーのクラス実装
 * @author	shibata
 */

#include "Player.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputKey.h>
#include <Sound.h>
#include "../Collider/Collider.h"
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"
#include "../StateManager/StateManager.h"

Player::Player(D3DXVECTOR2 initpos_) :
m_pInputKey(&InputKey::Instance()),
m_pSound(&Sound::Instance()),
m_pStateManager(&StateManager::Instance()),
m_jumpPower(JUMPPOWER),
m_gravity(GRAVITY),
m_freeGravity(GRAVITY),
m_moveSpeedX(MOVE_SPEED),
m_moveSpeedY(0),
m_gravityPower(0.1),
m_topFieldHits(false),
m_bottomFieldHits(false),
m_rightFieldHits(false),
m_leftFieldHits(false),
m_upFlag(false),
m_downFlag(false),
m_pCollider(new Collider(Collider::PLAYER_ID))
{
	m_pVertex = new Vertex;

	m_posX = initpos_.x;
	m_posY = initpos_.y;
	m_playerRect = { m_posX, m_posY, m_posX + PLAYER_SIZE, m_posY + PLAYER_SIZE };
	m_pVertex->SetTextureSize(PLAYER_SIZE, PLAYER_SIZE, 0.125, 0.125);

}

Player::~Player()
{
	delete m_pVertex;
}

void Player::Control()
{
	m_pInputKey->CheckKey(DIK_SPACE, SPACE);
	m_pInputKey->CheckKey(DIK_UP, UP);
	m_pInputKey->CheckKey(DIK_DOWN, DOWN);
	m_pInputKey->CheckKey(DIK_LEFT, LEFT);
	m_pInputKey->CheckKey(DIK_RIGHT, RIGHT);

	if (m_pInputKey->m_key[SPACE] == PUSH)
	{
		m_pSound->LoadSoundFile("Resource/Sound/sen_ka_yumi01.wav");
		m_pSound->SoundState(PLAY);
	}

	//他クラスに移動スピードを伝える
	DataManager::GetInstance().SetPlayerXMoveSpeed(m_moveSpeedX);
	DataManager::GetInstance().SetPlayerYMoveSpeed(m_moveSpeedY);

	//BasePointの矩形を受け取る
	m_basePointRect = DataManager::GetInstance().GetBasePoint();

	m_pCollider->SetRectData(m_playerRect);

	m_colliderIDs = m_pCollider->GetColliderIDs();

	for (unsigned int i = 0; i < m_colliderIDs.size(); i++)
	{
		if (m_colliderIDs[i] == Collider::ENEMYBULLET_ID)
		{
			//ダメージ関係の処理
		}
	}

	Move();

	DataManager::GetInstance().SetPositionData(m_posX, m_posY);

	m_pCollider->ClearColliderIDs();
}

void Player::Draw()
{
	m_pVertex->DrawLeftTop(m_posX, m_posY, m_pTexture);
}

void Player::Move()
{
	distance = DataManager::GetInstance().GetBasePointDistance();

	if (m_pInputKey->m_key[LEFT] == ON)
	{
		m_leftFieldHits = CollisionManager::getInstance().HasHitField(m_playerRect.left - m_moveSpeedX, m_playerRect.bottom - 30, distance);
		DataManager::GetInstance().SetPlayerFieldHits(m_leftFieldHits);

		if (m_leftFieldHits == false)
		{
			if (m_basePointRect.left < m_posX)
			{
				m_playerRect.right -= m_moveSpeedX;
				m_playerRect.left -= m_moveSpeedX;
				m_posX -= m_moveSpeedX;
			}
		}
	}
	if (m_pInputKey->m_key[RIGHT] == ON)
	{
		m_rightFieldHits = CollisionManager::getInstance().HasHitField(m_playerRect.right + m_moveSpeedX, m_playerRect.bottom - 30, distance);
		DataManager::GetInstance().SetPlayerFieldHits(m_rightFieldHits);
		
		if (m_rightFieldHits == false)
		{
			if (m_basePointRect.right > m_posX)
			{
				m_playerRect.right += m_moveSpeedX;
				m_playerRect.left += m_moveSpeedX;
				m_posX += m_moveSpeedX;
			}
		}
	}
	if (m_pInputKey->m_key[UP] == PUSH)
	{
		m_topFieldHits = CollisionManager::getInstance().HasHitField(m_playerRect.right - 60, m_playerRect.top, distance);
		DataManager::GetInstance().SetPlayerFieldHits(m_topFieldHits);

		if (m_topFieldHits == false)
		{
			if (m_bottomFieldHits)
			{
				m_isJump = true;
				m_upFlag = true;
			}
		}
	}

	if (m_isJump)
	{
		m_bottomFieldHits = CollisionManager::getInstance().HasHitField(m_playerRect.right - 60, m_playerRect.bottom - m_jumpPower, distance);
		DataManager::GetInstance().SetPlayerFieldHits(m_bottomFieldHits);

		if (m_upFlag)
		{
			m_playerRect.top -= m_jumpPower;
			m_playerRect.bottom -= m_jumpPower;
			m_posY -= m_jumpPower;
		}

		if (m_basePointRect.top >= m_posY)
		{
			m_moveSpeedY = m_jumpPower;
			m_upFlag = false;			
		}

		m_jumpPower -= m_gravity;

		if (m_gravity < 1)
		{
			m_gravity += m_gravityPower;
		}

		if (m_jumpPower <= 0)
		{
			m_jumpPower = JUMPPOWER;
			m_gravity = GRAVITY;
			m_isJump = false;
		}
	}

	m_bottomFieldHits = CollisionManager::getInstance().HasHitField(m_playerRect.right - 60, m_playerRect.bottom + m_freeGravity, distance);
	DataManager::GetInstance().SetPlayerFieldHits(m_bottomFieldHits);

	if (m_bottomFieldHits == false)
	{
		m_downFlag = true;

		if (m_isJump == false)
		{
			if (m_basePointRect.bottom <= m_posY)
			{
				m_moveSpeedY = m_freeGravity;
				m_downFlag = false;
			}

			if (m_downFlag)
			{
				m_playerRect.top += m_freeGravity;
				m_playerRect.bottom += m_freeGravity;
				m_posY += m_freeGravity;
			}

			if (m_freeGravity < 10)
			{
				m_freeGravity += m_gravityPower;
			}


			if (m_bottomFieldHits)
			{
				m_freeGravity = GRAVITY;
				m_playerRect.top -= 32;
				m_playerRect.bottom -= 32;
				m_posY -= 32;
			}
		}
	}
}

VectorDirection Player::VectorOrient()
{
	if (m_pInputKey->m_key[A] == ON)
	{
		m_vectorDirection = VECTOR_LEFT;
	}
	if (m_pInputKey->m_key[D] == ON)
	{
		m_vectorDirection = VECTOR_RIGHT;
	}
	if (m_pInputKey->m_key[W] == PUSH)
	{
		m_vectorDirection = VECTOR_UP;
	}
	if (m_pInputKey->m_key[S] == PUSH)
	{
		m_vectorDirection = VECTOR_DOWN;
	}

	return m_vectorDirection;
}