#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "Sound.h"
#include <vector>

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void LoadSoundFile(int index_, TCHAR* filepath_);

	void SoundState(int index_, Sound::SoundMode soundstate_);

private:

	std::vector<Sound*> m_pSound;
};
#endif // !SOUNDMANAGER_H