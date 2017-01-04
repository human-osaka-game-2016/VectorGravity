#include "VectorIcon.h"
#include <Texture.h>
#include <Vertex.h>
#include "../StateManager/StateManager.h"
#include "../ObjectManager/ObjectManager.h"

VectorIcon::VectorIcon() : 
m_kiconPosX(64.0f),
m_kiconPosY(32.0f),
m_kiconSize(64.0f)
{
	m_pTexture->LoadTexture("Resource/Texture/VectorIcon.png");
}

VectorIcon::~VectorIcon()
{
	delete m_pTexture;
	delete m_pVertex;
}

void VectorIcon::Draw()
{
	m_pVertex->DrawLeftTop(m_kiconPosX, m_kiconPosY, m_pTexture);

	switch (m_pStateManager->GetVectorDirection())
	{
	case VECTOR_UP:
		DrawIcon(0.5f, 1.0f, 0.25f, 0.0f);
		break;	 
				 
	case VECTOR_DOWN:
		DrawIcon(0.25f, 1.0f, 0.0f, 0.0f);
		break;

	case VECTOR_RIGHT:
		DrawIcon(0.75f, 1.0f, 0.5f, 0.0f);
		break;

	case VECTOR_LEFT:
		DrawIcon(1.0f, 1.0f, 0.75f, 0.0f);
		break;
	}
}

void VectorIcon::DrawIcon(float maxtu_, float maxtv_, float mintu_, float mintv_)
{
	m_iconMaxTu = maxtu_;
	m_iconMaxTv = maxtv_;
	m_iconMinTu = mintu_;
	m_iconMinTv = mintv_;

	m_pVertex->SetTextureSize(m_kiconSize, m_kiconSize, m_iconMaxTu, m_iconMaxTv, m_iconMinTu, m_iconMinTv);
}
