#pragma once
#include <random>
#include <ctime>
#include <Windows.h>
#include "queue.h"
#include "globalvar.h"
#include "stdafx.h"
#include "function.h"

class PassengerGenerator
{
private:
	int m_AutoSwitch;
	class RestArea *RestPoint = NULL;
	int m_maxid = 0;
	time_t interval = 1000;
	void addPassenger(int num);
	//��˹�ֲ��Զ�����,����Ϊ��ֵ������
	
public:
	void gauss();
	//��������Ϣ�������ӣ�����ָ��
	void setRestArea(RestArea *p);
	void auto_start();
	void auto_stop();
	void addSingle();
	void add(int num);
	//���÷������
	void setInterval(time_t ti);
	time_t getInterval();
	
};