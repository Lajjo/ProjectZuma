#include "ljud.h"
#include "fmod.h"
#include "fmod.hpp"
#include "fmod_event.h"
#include "fmod_event.hpp"
#include "fmod_event_net.h"
#include "fmod_event_net.hpp"
#include <string>

void ljud::Init()
{
	//intiatlize fmod system
	result = FMOD::EventSystem_Create(&fmodSystem);
	result = fmodSystem->init(1024, FMOD_INIT_NORMAL, 0, FMOD_EVENT_INIT_NORMAL);
	result = FMOD::NetEventSystem_Init(fmodSystem, 0);

	//Load sounds
	result = fmodSystem->load("../FMOD/Designer_Test.fev", FMOD_EVENT_INIT_NORMAL, &fmodProject);
	result = fmodProject->getGroup("SFX", true, &SFX);
	result = fmodProject->getGroup("Music", false, &Music);
	result = SFX->getEvent("footstep", FMOD_EVENT_DEFAULT, &footstep);
	result = Music->getEvent("BG", FMOD_EVENT_DEFAULT, &BG);
	eventVector.push_back(footstep);
	eventVector.push_back(BG);

}

void ljud::Update(void)
{
	result = fmodSystem->update();
	FMOD::NetEventSystem_Update();
}

void ljud::PlaySound(int i)
{
	eventVector[i]->start();
}

void ljud::PlayMusic()
{
	BG->start();
}

void ljud::StopSound()
{

}