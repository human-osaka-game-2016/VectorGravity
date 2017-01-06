#include "LongSoldier.h"
#include <Vertex.h>
#include <Texture.h>
#include <InputKey.h>
#include <InputContlloer.h>
#include <SoundManager.h>
#include "../Collider/Collider.h"
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"
#include "../StateManager/StateManager.h"
#include "../ObjectManager/ObjectManager.h"
#include "../Bullet/EnemyBulletManager.h"

LongSoldier::LongSoldier(D3DXVECTOR2 initpos_) :
m_pStateManager(&StateManager::Instance()),
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_pEnemyBulletManager(new EnemyBulletManager),
m_pSoundManager(new SoundManager),
m_hits(false),
m_soldierhits(false),
m_XBlow(0),
m_YBlow(0),
m_playerPosX(0),
m_playerPosY(0),
m_playerDistance(0),
m_searchRange(400),
m_pCollider(new Collider(Collider::SOLDIER_ID))
{
	m_pVertex2 = new Vertex;
	m_pVertex2->SetTextureSize(LONGSOLDIER_SIZE, LONGSOLDIER_SIZE, 0.25, 0.5, 0.125, 0.375);

	m_posX = initpos_.x;
	m_posY = initpos_.y;

	m_longSoldierRect = { m_posX, m_posY, m_posX + LONGSOLDIER_SIZE, m_posY + LONGSOLDIER_SIZE };

	m_isDeath = false;

	DataManager::GetInstance().SetEnemyPositionData(m_posX, m_posY);
	CollisionManager::getInstance().SetCollider(m_pCollider);

	m_pSoundManager->LoadSoundFile(ACTIV_TRIGGER, "Resource/Sound/BG_Invocation01.wav");
	m_pSoundManager->LoadSoundFile(BLOW_WAY, "Resource/Sound/BG_EBlowaway01.wav");
	m_pSoundManager->LoadSoundFile(ENEMY_REFLECT, "Resource/Sound/BG_EReflection01.wav");
}

LongSoldier::~LongSoldier()
{
	delete m_pTexture;
	delete m_pVertex2;
	delete m_pCollider;
	delete m_pEnemyBulletManager;
	delete m_pSoundManager;
}

void LongSoldier::Control()
{
	m_base = DataManager::GetInstance().GetBasePointDistance();

	m_baseRect.left   = m_longSoldierRect.left - m_base.x;
	m_baseRect.top    = m_longSoldierRect.top - m_base.y;
	m_baseRect.right  = m_longSoldierRect.right - m_base.x;
	m_baseRect.bottom = m_longSoldierRect.bottom - m_base.y;

	m_pCollider->SetRectData(m_baseRect);

	m_pInputKey->CheckKey(DIK_LCONTROL, LCONTROL);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_B, B_BUTTON);
	m_pInputContlloer->CheckTriger(RIGHT_TRIGGER);

	m_colliderIDs = m_pCollider->GetColliderIDs();

	for (int i = 0; i < m_colliderIDs.size(); i++)
	{
		if (m_colliderIDs[i] == Collider::NORMALBULLET_ID)
		{
			m_hits = true;
		}
		if (m_colliderIDs[i] == Collider::PLAYER_ID)
		{
		}
		if (m_colliderIDs[i] == Collider::SOLDIER_ID)
		{
			m_soldierhits = true;
			m_isDeath = true;
		}
	}

	m_rightFieldHits  = CollisionManager::getInstance().HasHitField(m_longSoldierRect.right,      m_longSoldierRect.bottom - 64, D3DXVECTOR2(0, 0));
	m_leftFieldHits   = CollisionManager::getInstance().HasHitField(m_longSoldierRect.left,       m_longSoldierRect.bottom - 64, D3DXVECTOR2(0, 0));
	m_topFieldHits    = CollisionManager::getInstance().HasHitField(m_longSoldierRect.left + 64,  m_longSoldierRect.top, D3DXVECTOR2(0, 0));
	m_bottomFieldHits = CollisionManager::getInstance().HasHitField(m_longSoldierRect.right - 64, m_longSoldierRect.bottom - 20, D3DXVECTOR2(0, 0));


	if (m_rightFieldHits == true)
	{
		m_pSoundManager->SoundState(ENEMY_REFLECT, Sound::PLAY);
		m_isDeath = true;
		m_XBlow = 0;
		m_XBlow -= BLOWSPEED;
		m_rightFieldHits = false;
	}

	if (m_leftFieldHits == true)
	{
		m_pSoundManager->SoundState(ENEMY_REFLECT, Sound::PLAY);
		m_isDeath = true;
		m_XBlow = 0;
		m_XBlow += BLOWSPEED;
		m_leftFieldHits = false;
	}

	if (m_topFieldHits == true)
	{
		m_pSoundManager->SoundState(ENEMY_REFLECT, Sound::PLAY);
		m_isDeath = true;
		m_YBlow = 0;
		m_YBlow += BLOWSPEED;
		m_topFieldHits = false;
	}

	if (m_bottomFieldHits == true)
	{
		m_pSoundManager->SoundState(ENEMY_REFLECT, Sound::PLAY);
		m_isDeath = true;
		m_YBlow = 0;
		m_YBlow -= BLOWSPEED;
		m_bottomFieldHits = false;
	}

	if (m_hits == true)
	{
		if (m_pInputKey->m_key[LCONTROL] == ON || m_pInputContlloer->m_padButton[CONTLLOER_1][B_BUTTON] == PAD_PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][RIGHT_TRIGGER] == PAD_ON)
		{
			m_pSoundManager->SoundState(ACTIV_TRIGGER, Sound::PLAY);
			m_pSoundManager->SoundState(BLOW_WAY, Sound::PLAY);
			switch (m_pStateManager->GetVectorDirection())
			{
			case VECTOR_UP:

				m_YBlow = -BLOWSPEED;

				break;

			case VECTOR_DOWN:

				m_YBlow = BLOWSPEED;

				break;

			case VECTOR_LEFT:

				m_XBlow = -BLOWSPEED;

				break;

			case VECTOR_RIGHT:

				m_XBlow = BLOWSPEED;

				break;

			}
		}
	}

	m_longSoldierRect.right  += m_XBlow;
	m_longSoldierRect.left   += m_XBlow;
	m_longSoldierRect.top    += m_YBlow;
	m_longSoldierRect.bottom += m_YBlow;
	m_posX += m_XBlow;
	m_posY += m_YBlow;

	//m_pEnemyBulletManager->Control();

	/*Search();

	if (m_playerDistance <= m_searchRange)
	{
		Attack();
	}*/

	m_pCollider->ClearColliderIDs();
}

void LongSoldier::Draw()
{
	//m_pEnemyBulletManager->Draw();
	m_pVertex2->DrawLeftTop(m_posX - m_base.x, m_posY - m_base.y, m_pTexture);
	m_pVertex2->SetColor(0xFFFFFFFF);

	if (m_hits == true)
	{
		m_pVertex2->SetTextureSize(LONGSOLDIER_SIZE, LONGSOLDIER_SIZE, 0.625, 0.5, 0.5, 0.375);
	}
	else if (m_soldierhits == true)
	{
		m_pVertex2->SetTextureSize(LONGSOLDIER_SIZE, LONGSOLDIER_SIZE, 0.75, 0.5, 0.625, 0.375);
	}
}

void LongSoldier::Attack()
{
	m_pEnemyBulletManager->CreateBullet(SOLDIER);
}

void LongSoldier::Search()
{
	m_playerPosX = DataManager::GetInstance().GetPlayerPositionXData();
	m_playerPosY = DataManager::GetInstance().GetPlayerPositionYData();

	m_playerDistance = pow((m_playerPosX - m_posX)*(m_playerPosX - m_posX) + (m_playerPosY - m_posY)*(m_playerPosY - m_posY), 0.5);

}