#pragma once

typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;
}INFO;

typedef struct tagFrame
{
	int iFrameStart;
	int iFrameEnd;
	int iFrameScene;
	long long tFrameSpeed;
	system_clock::time_point tFrameTime;
}FRAME;

typedef struct tagMedal
{
	bool PerfectMedal;
	bool SuperbMedal;
	bool OKMedal;
	bool NullMedal;
}MEDALS;