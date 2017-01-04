#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
	for (unsigned int i = 0; i < m_pSound.size(); i++)
	{
		delete m_pSound[i];
	}
}

void SoundManager::LoadSoundFile(int index_, TCHAR* filepath_)
{
	m_pSound.push_back(new Sound);

	m_pSound[index_]->LoadSoundFile(filepath_);
}

void SoundManager::SoundState(int index_, Sound::SoundMode soundstate_)
{
	m_pSound[index_]->SoundState(soundstate_);
}