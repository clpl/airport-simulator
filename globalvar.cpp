#include "stdafx.h"
#include "globalvar.h"
#include "checkpoint.h"

int MinCheck = 4;
int MaxCheck = 8;
int MaxCustSingleLine = 20;
int MaxCustSingleSkew = 2;
int MaxLines = 4;
int MaxSeqLen = 10;
int EasySeqLen = 2;
int MaxCustCheck = 5;
int MaxSec = 5;
int MaxRestNum = 1000;
int distributionMethod = 0;
bool isoffDuty=false;
time_t t_unit = 200;

int MaxCustNum;

int curFreeRtp = 0;
// 打开动画
bool aniWindow = false;
bool initFinished = false;

SerpQueue SerpQ;


//enum int {onDuty,offDuty,pause,closed};
