#include "VectorIcon.h"
#include "../StateManager/StateManager.h"

VectorIcon::VectorIcon() : m_pStateManager(&StateManager::GetInstance())
{
	m_texture.LoadTexture("Resource/Texture/VectorIcon.png");
	m_vecrotIcon = { 106, 0, 170, 64};
}

VectorIcon::~VectorIcon()
{

}

void VectorIcon::Control()
{

}

void VectorIcon::Draw()
{
	m_vectorDirection = m_pStateManager->GetVectorDirection();

	switch (m_vectorDirection)
	{
	case Vector_Up:
	{

		CUSTOMVERTEX UpVectorIcon[4]
		{
			{ m_vecrotIcon.left, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f},
			{ m_vecrotIcon.right, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, -1.f, 0.f },
			{ m_vecrotIcon.right, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, -1.f, -1.f },
			{ m_vecrotIcon.left, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, -1.f }
		};

		m_texture.SetTexture(UpVectorIcon);
	}
		break;
	
	case Vector_Down:
	{
		CUSTOMVERTEX DownVectorIcon[4]
		{
			{ m_vecrotIcon.left, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f},
			{ m_vecrotIcon.right, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ m_vecrotIcon.right, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ m_vecrotIcon.left, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};

		m_texture.SetTexture(DownVectorIcon);
	}
		break;

	case Vector_Left:
	{
		CUSTOMVERTEX LeftVectorIcon[4]
		{
			{ m_vecrotIcon.left, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f},
			{ m_vecrotIcon.right, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ m_vecrotIcon.right, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ m_vecrotIcon.left, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f }
		};

		m_texture.SetTexture(LeftVectorIcon);
	}

		break;

	case Vector_Right:
	{
		CUSTOMVERTEX RightVectorIcon[4]
		{
			{ m_vecrotIcon.left, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f},
			{ m_vecrotIcon.right, m_vecrotIcon.top, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ m_vecrotIcon.right, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f },
			{ m_vecrotIcon.left, m_vecrotIcon.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f }
		};

		m_texture.SetTexture(RightVectorIcon);
	}

		break;

	//case Vector_Up_Left:

	//	break;

	//case Vector_Up_Right:

	//	break;

	//case Vector_Down_Left:

	//	break;

	//case Vector_Down_Right:

	//	break;
	}
}

