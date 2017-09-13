#include "stdafx.h"
#include <vector>
#include "globalvar.h"
#include "queue.h"
#include "checkpoint.h"
#include "function.h"

void CheckPoint::start() {
    if(state != offDuty) {
        state = onDuty;
    }
}

void CheckPoint::pause(int pauseTime)
{
	if (state != offDuty && state != closed)
	{
		state = offDuty;
		nextPopTime += pauseTime;
		pauseEndTime = getTime() + pauseTime;
	}
}

bool CheckPoint::isFull() {
    return getNum() >= MaxCustCheck;
}

int CheckPoint::getState() {
    return state;
}

void CheckPoint::refreshNum() {
    if(!isempty()&&getTime()>nextPopTime)
        popPassenger();
}

void CheckPoint::refreshPopTime() {
    if(getTime()>nextPopTime)
    {
        popPassenger();
        nextPopTime=getTime()+getFirstPassenger().checkTime;
    }
}