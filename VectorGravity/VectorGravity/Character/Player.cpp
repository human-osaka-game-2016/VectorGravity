/**
* @file	Player.cpp
* @breif	プレイヤーのクラス実装
* @author	shibata
*/

#include "Player.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputKey.h>
#include <InputContlloer.h>
#include <SoundManager.h>
#include "../Collider/Collider.h"
#include "../Collider/CollisionManager.h"
#include "../DataManager/DataManager.h"
#include "../StateManager/StateManager.h"
#include "../Bullet/PlayerBulletManager.h"
#include "../Scene/GameScene.h"
#include "../ObjectManager/ObjectManager.h"

Player::Player(D3DXVECTOR2 initpos_) :
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_pStateManager(&StateManager::Instance()),
m_playerBulletManager(new PlayerBulletManager),
m_pSoundManager(new SoundManager),
m_jumpPower(JUMP_POWER),
m_gravity(GRAVITY),
m_freeGravity(GRAVITY),
m_moveSpeedX(MOVE_SPEED),
m_moveSpeedY(0),
m_gravityPower(0.1),
m_isStageClear(false),
m_topFieldHits(false),
m_bottomFieldHits(false),
m_rightFieldHits(false),
m_leftFieldHits(false),
m_damageHit(false),
m_isUpScrolling(false),
m_isDownScrolling(false),
m_stagePos(0, 0),
m_Hp(300),
m_Gp(300),
m_recoveryGp(1),
m_damageInterval(0),
m_vectorDirection(VECTOR_UP),
m_pCollider(new Collider(Collider::PLAYER_ID))
{
	m_pVertex = new Vertex;

	m_isDeath = false;

	m_stagePos = initpos_;
	m_posX = initpos_.x;
	m_posY = initpos_.y;
	m_playerRect = { m_posX, m_posY, m_posX + PLAYER_SIZE, m_posY + PLAYER_SIZE };
	m_pVertex->SetTextureSize(PLAYER_SIZE, PLAYER_SIZE, 0.125, 0.125);
	m_pSoundManager->LoadSoundFile(PLAYER_ATTACK, "Resource/Sound/BG_firing01.wav");
	m_pSoundManager->LoadSoundFile(VECTOR_CHANGE, "Resource/Sound/BG_Change01.wav");
	m_pSoundManager->LoadSoundFile(PLAYER_DAMAGE, "Resource/Sound/BG_Damage01.wav");
	m_pSoundManager->LoadSoundFile(PLAYER_JUMP, "Resource/Sound/BG_Jump01.wav");
	m_pSoundManager->LoadSoundFile(PLAYER_GPRECOVER, "Resource/Sound/BG_GPRecovery01.wav");
	m_pSoundManager->LoadSoundFile(PLAYER_LAND, "Resource/Sound/BG_Landing01.wav");

	CollisionManager::GetInstance()->SetCollider(m_pCollider);
}

Player::~Player()
{
	delete m_pVertex;
	delete m_pCollider;
	delete m_pSoundManager;
	delete m_playerBulletManager;
	delete m_pTexture;
}

void Player::Control()
{
	m_pInputKey->CheckKey(DIK_A, A);
	m_pInputKey->CheckKey(DIK_D, D);
	m_pInputKey->CheckKey(DIK_W, W);
	m_pInputKey->CheckKey(DIK_S, S);
	m_pInputKey->CheckKey(DIK_SPACE, SPACE);
	m_pInputKey->CheckKey(DIK_UP, UP);
	m_pInputKey->CheckKey(DIK_DOWN, DOWN);
	m_pInputKey->CheckKey(DIK_LEFT, LEFT);
	m_pInputKey->CheckKey(DIK_RIGHT, RIGHT);
	m_pInputKey->CheckKey(DIK_A, A);
	m_pInputKey->CheckKey(DIK_S, S);
	m_pInputKey->CheckKey(DIK_D, D);
	m_pInputKey->CheckKey(DIK_W, W);

	m_pInputContlloer->CheckStick(LEFT_THUMBSTICK, STICK_LEFT);
	m_pInputContlloer->CheckStick(LEFT_THUMBSTICK, STICK_RIGHT);
	m_pInputContlloer->CheckStick(LEFT_THUMBSTICK, STICK_UP);
	m_pInputContlloer->CheckTriger(RIGHT_TRIGGER);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_DPAD_UP, DPAD_UP);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, DPAD_DOWN);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, DPAD_LEFT);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, DPAD_RIGHT);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_A, A_BUTTON);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_X, X_BUTTON);

	

	//他クラスに移動スピードを伝える
	DataManager::GetInstance()->SetPlayerXMoveSpeed(m_moveSpeedX);
	DataManager::GetInstance()->SetPlayerYMoveSpeed(m_moveSpeedY);

	//BasePointの矩形を受け取る
	m_basePointRect = DataManager::GetInstance()->GetBasePoint();

	m_pCollider->SetRectData(m_playerRect);

	m_colliderIDs = m_pCollider->GetColliderIDs();

	if (m_damageHit == false)
	{
		for (unsigned int i = 0; i < m_colliderIDs.size(); i++)
		{
			if (m_colliderIDs[i] == Collider::ENEMYBULLET_ID)
			{
				m_Hp -= 38;  //暫定的な兵士との接触ダメージ
				m_pSoundManager->SoundState(PLAYER_DAMAGE, Sound::RESET_PLAY);
				m_damageHit = true;
			}
			if (m_colliderIDs[i] == Collider::SOLDIER_ID)
			{
				m_Hp -= 38;  //暫定的な兵士との接触ダメージ
				m_pSoundManager->SoundState(PLAYER_DAMAGE, Sound::RESET_PLAY);
				m_damageHit = true;
			}
			if (m_colliderIDs[i] == Collider::GOALPOINT_ID)
			{
				m_isStageClear = true;
			}
		}
	}

	//無敵時間初期化
	if (m_damageHit)
	{

		m_damageInterval += 1;
		if (m_damageInterval == DAMAGE_INTERVAL)
		{
			m_damageHit = false;
			m_damageInterval = 0;
		}

		//点滅処理
		m_flashingCount++;
		if (m_flashingCount > FLASHTIME)
		{
			if (m_hitFlashing == false)
			{
				m_hitFlashing = true;
			}
			else if (m_hitFlashing == true)
			{
				m_hitFlashing = false;
			}
			m_flashingCount = 0;
		}
	}

	//死亡判定
	if (m_Hp <= 0)
	{
		m_isDeath = true;
	}
	else if (DataManager::GetInstance()->GetBasePointDistance().y > 1300)
	{
		m_isDeath = true;
	}

	//GP回復処理
	if (m_Gp < 300)
	{
		m_Gp += m_recoveryGp; //１フレーム1回復　1秒間に60回復　回復量は後で変える予定あり

		if (m_Gp == 300)
		{
			m_pSoundManager->SoundState(PLAYER_GPRECOVER, Sound::PLAY);
		}
	}



	m_playerBulletManager->Control();
	m_vectorDirection = VectorOrient();
	Attack();
	Move();

	StateManager::Instance().SetPlayerHp(m_Hp);
	StateManager::Instance().SetPlayerGp(m_Gp);
	DataManager::GetInstance()->SetPlayerDead(m_isDeath);
	DataManager::GetInstance()->SetStageClear(m_isStageClear);

	m_pStateManager->SetVectorDirection(m_vectorDirection);

	DataManager::GetInstance()->SetPlayerDirection(m_playerDirection);

	DataManager::GetInstance()->SetPlayerPositionData(m_posX, m_posY);
	//DataManager::GetInstance()->SetPlayerPositionData(m_stagePos.x, m_stagePos.y);

	m_pCollider->ClearColliderIDs();
}

void Player::Draw()
{
	m_playerBulletManager->Draw();
	m_pVertex->DrawLeftTop(m_posX, m_posY, m_pTexture);

	if (m_damageHit)
	{
		if (m_flashingCount != 0)
		{
			if (m_hitFlashing)
			{
				m_pVertex->SetColor(0xFFFFFFFF);
			}
			else if (m_hitFlashing == false)
			{
				m_pVertex->SetColor(0x00FFFFFF);
			}
		}
	}
	else
	{
		m_pVertex->SetColor(0xFFFFFFFF);
	}
	
}

void Player::Attack()
{
	if (m_Gp >= 75)
	{
		if (m_pInputKey->m_key[SPACE] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][X_BUTTON] == PAD_PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][RIGHT_TRIGGER] == PAD_PUSH)
		{
			m_playerBulletManager->CreateBullet();
			m_pSoundManager->SoundState(PLAYER_ATTACK, Sound::RESET_PLAY);
			m_Gp -= 150;
		}
	}
}

void Player::Move()
{
	distance = DataManager::GetInstance()->GetBasePointDistance();

	if (m_pInputKey->m_key[LEFT] == ON || m_pInputContlloer->m_padStick[CONTLLOER_1][STICK_LEFT][LEFT_THUMBSTICK] == PAD_ON)
	{
		m_leftFieldHits = CollisionManager::GetInstance()->HasHitField(m_playerRect.left - m_moveSpeedX, m_playerRect.bottom - 30, distance);
		DataManager::GetInstance()->SetPlayerFieldHits(m_leftFieldHits);

		m_playerDirection = Direction_Left;

		if (m_leftFieldHits == false)
		{
			m_stagePos.x -= m_moveSpeedX;
			if (m_basePointRect.left < m_posX)
			{
				m_playerRect.right -= m_moveSpeedX;
				m_playerRect.left -= m_moveSpeedX;
				m_posX -= m_moveSpeedX;
			}
		}
	}
	if (m_pInputKey->m_key[RIGHT] == ON || m_pInputContlloer->m_padStick[CONTLLOER_1][STICK_RIGHT][LEFT_THUMBSTICK] == PAD_ON)
	{
		m_rightFieldHits = CollisionManager::GetInstance()->HasHitField(m_playerRect.right + m_moveSpeedX, m_playerRect.bottom - 30, distance);
		DataManager::GetInstance()->SetPlayerFieldHits(m_rightFieldHits);
		
		m_playerDirection = Direction_Right;

		if (m_rightFieldHits == false)
		{
			m_stagePos.x += m_moveSpeedX;
			if (m_basePointRect.right > m_posX)
			{
				m_playerRect.right += m_moveSpeedX;
				m_playerRect.left += m_moveSpeedX;
				m_posX += m_moveSpeedX;
			}
		}
	}
	if (m_pInputKey->m_key[UP] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][A_BUTTON] == PAD_PUSH || m_pInputContlloer->m_padStick[CONTLLOER_1][STICK_UP][LEFT_THUMBSTICK] == PAD_ON)
	{

		m_topFieldHits = CollisionManager::GetInstance()->HasHitField(m_playerRect.right - 60, m_playerRect.top, distance);
		DataManager::GetInstance()->SetPlayerFieldHits(m_topFieldHits);

		if (m_topFieldHits == false)
		{
			if (m_bottomFieldHits)
			{
				m_isJump = true;
				m_isUpScrolling = true;
				m_pSoundManager->SoundState(PLAYER_JUMP, Sound::RESET_PLAY);
			}
		}
	}

	if (m_isJump)
	{
		m_bottomFieldHits = CollisionManager::GetInstance()->HasHitField(m_playerRect.right - 60, m_playerRect.bottom - m_jumpPower, distance);
		DataManager::GetInstance()->SetPlayerFieldHits(m_bottomFieldHits);

		if (m_isUpScrolling)
		{
			m_stagePos.y -= m_jumpPower;
			m_playerRect.top -= m_jumpPower;
			m_playerRect.bottom -= m_jumpPower;
			m_posY -= m_jumpPower;
		}

		if (m_basePointRect.top >= m_posY)
		{
			m_moveSpeedY = m_jumpPower;
			m_isUpScrolling = false;
		}

		m_jumpPower -= m_gravity;

		if (m_gravity < 1)
		{
			m_gravity += m_gravityPower;
		}

		if (m_jumpPower <= 0)
		{
			m_jumpPower = JUMP_POWER;
			m_gravity = GRAVITY;
			m_isJump = false;
			m_isLand = true;
		}
	}

	m_bottomFieldHits = CollisionManager::GetInstance()->HasHitField(m_playerRect.right - 60, m_playerRect.bottom + m_freeGravity, distance);
	DataManager::GetInstance()->SetPlayerFieldHits(m_bottomFieldHits);

	if (m_bottomFieldHits && !m_isJump && m_isLand)
	{
		m_pSoundManager->SoundState(PLAYER_LAND, Sound::PLAY);
		m_isLand = false;
	}
	if (m_bottomFieldHits == false)
	{
		m_isDownScrolling = true;

		if (m_isJump == false)
		{

			if (m_basePointRect.bottom <= m_posY)
			{
				m_moveSpeedY = m_freeGravity;
				m_isDownScrolling = false;
			}

			if (m_isDownScrolling)
			{
				m_stagePos.y += m_freeGravity;
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
	if (m_pInputKey->m_key[A] == ON || m_pInputContlloer->m_padButton[CONTLLOER_1][DPAD_LEFT] == PAD_PUSH)
	{
		m_pSoundManager->SoundState(VECTOR_CHANGE, Sound::RESET_PLAY);
		m_vectorDirection = VECTOR_LEFT;
	}
	if (m_pInputKey->m_key[D] == ON || m_pInputContlloer->m_padButton[CONTLLOER_1][DPAD_RIGHT] == PAD_PUSH)
	{
		m_pSoundManager->SoundState(VECTOR_CHANGE, Sound::RESET_PLAY);
		m_vectorDirection = VECTOR_RIGHT;
	}
	if (m_pInputKey->m_key[W] == ON || m_pInputContlloer->m_padButton[CONTLLOER_1][DPAD_UP] == PAD_PUSH)
	{
		m_pSoundManager->SoundState(VECTOR_CHANGE, Sound::RESET_PLAY);
		m_vectorDirection = VECTOR_UP;
	}
	if (m_pInputKey->m_key[S] == ON || m_pInputContlloer->m_padButton[CONTLLOER_1][DPAD_DOWN] == PAD_PUSH)
	{
		m_pSoundManager->SoundState(VECTOR_CHANGE, Sound::RESET_PLAY);
		m_vectorDirection = VECTOR_DOWN;
	}


	return m_vectorDirection;
}