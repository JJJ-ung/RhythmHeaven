#include "stdafx.h"
#include "MainPlayer.h"

IMPLEMENT_SINGLETON(CMainPlayer)

CMainPlayer::CMainPlayer()
{
}


CMainPlayer::~CMainPlayer()
{
}

void CMainPlayer::Initialize()
{
	Rhythm_Stat = 0;
	m_iPerfect = 0;
	m_iGood = 0;
	m_iBad = 0;
	m_iBirdCount = 0;
	m_iFanCount = 0;
	m_iLizardCount = 0;
	m_tBirds = {false, false, false, true};
	m_tLizard = { false, false, false, true };
	m_tFanClub = { false, false, false, true };
}

void CMainPlayer::Set_Perfect_Medal()
{
	m_tBirds = { true, false, false, false };
	m_tLizard = { true, false, false, false };
	m_tFanClub = { true, false, false, false };
}

void CMainPlayer::Set_Superb_Medal()
{
	m_tBirds = { false, true, false, false };
	m_tLizard = { false, true, false, false };
	m_tFanClub = { false, true, false, false };
}

void CMainPlayer::Set_OK_Medal()
{
	m_tBirds = { false, false, true, false };
	m_tLizard = { false, false, true, false };
	m_tFanClub = { false, false, true, false };
}

void CMainPlayer::Set_Null_Medal()
{
	m_tBirds = { false, false, false, true };
	m_tLizard = { false, false, false, true };
	m_tFanClub = { false, false, false, true };
}

void CMainPlayer::Set_All_Medal()
{
	m_tBirds = { true, true, true, true };
	m_tLizard = { true, true, true, true };
	m_tFanClub = { true, true, true, true };
}
