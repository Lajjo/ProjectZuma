#pragma once

#include "fmod.h"
#include "fmod.hpp"
#include "fmod_event.h"
#include "fmod_event.hpp"
#include "fmod_event_net.h"
#include "fmod_event_net.hpp"
#include <vector>




class ljud
{
public:
	void Init();
	void Update();
	void PlaySound(int i);
	void PlayMusic();
	void StopSound();
	void ChangeVolume(int i);

private:
	FMOD::EventSystem *fmodSystem;
	FMOD::EventProject *fmodProject;
	FMOD_RESULT result;

	FMOD::EventGroup *SFX;
	FMOD::EventGroup *Music;
	FMOD::Event *footstep;
	//FMOD::Event *footstep2;
	FMOD::Event *BG;
	typedef std::vector<FMOD::Event*> EventVector;
	EventVector eventVector;
	


};

