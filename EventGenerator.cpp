#include <windows.h>
#include "stdafx.h"
#include "EventGenerator.h"
#include "globalvar.h"

EventGenerator::EventGenerator()
{
	eventStart();
}


EventGenerator::~EventGenerator()
{
}

void EventGenerator::eventStart()
{
	srand((unsigned)time(NULL));
	if (rand() % 100 > 90)
	{
		int id = rand() % MaxCheck;
		if (CheckP[id]->getState() == onDuty)
			CheckP[id]->toPause(rand() % 20);
	}
	if (rand() % 11 == 1 && getTime() > 100)
	{
		programEnd(CheckP,SerpQ);
	}
}

void EventGenerator::set(PassengerGenerator *PG,CheckPoint **CheckP,SerpQueue *SerpQ)
{
	this->PG = PG;
	this->CheckP = CheckP;
	this->SerpQ = SerpQ;
}