#include "stdafx.h"
#include "Scene.h"
#include "MouseMgr.h"
#include "MainPlayer.h"

CScene::CScene()
{
	m_iCount = 0;
}


CScene::~CScene()
{
}

void CScene::FrameMove()
{
	if (duration_cast<milliseconds>(system_clock::now() - m_tFrame.tFrameTime).count() > m_tFrame.tFrameSpeed)
	{
		++m_tFrame.iFrameStart;
		m_tFrame.tFrameTime = system_clock::now();
	}
	if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		m_tFrame.iFrameStart = 0;
}

void CScene::UpdateRect()
{
	m_tRect.left = LONG(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = LONG(m_tInfo.fY - (LONG(m_tInfo.fCY) >> 1));
	m_tRect.right = LONG(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = LONG(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}

JudgeID::ID CScene::Judge()
{
	JudgeID::ID _judge = JudgeID::NOTHING;
	if (iter_Note != m_vNote.end())
	{
		if ((*iter_Note).first == MotionID::MOTION_TOUCH)
		{
			if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_TOUCH)
			{
				if (m_lDuration < (*iter_Note).second + 8 && m_lDuration >(*iter_Note).second - 8)
				{
					_judge = JudgeID::PERFECT;
				}
				else if (m_lDuration < (*iter_Note).second + 70 && m_lDuration >(*iter_Note).second - 70)
				{
					_judge = JudgeID::GOOD;
				}
				else
				{
					_judge = JudgeID::BAD;
				}
			}
		}
		else if ((*iter_Note).first == MotionID::MOTION_SLIDE)
		{
			if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SLIDE)
			{
				if (m_lDuration < (*iter_Note).second + 10 && m_lDuration >(*iter_Note).second - 10)
				{
					_judge = JudgeID::PERFECT;
				}
				else if (m_lDuration < (*iter_Note).second + 80 && m_lDuration >(*iter_Note).second - 80)
				{
					_judge = JudgeID::GOOD;
				}
				else
				{
					_judge = JudgeID::BAD;
				}
			}
		}
	}

	if (iter_Note == m_vNote.end())
	{
		iter_Note = m_vNote.end();
	}
	else
	{
		if (m_lDuration > (*iter_Note).second + 100)
		{
			if (_judge = JudgeID::NOTHING)
				_judge = JudgeID::BAD;
			++iter_Note;
		}
	}

	return _judge;
}

JudgeID::ID CScene::Judge_Lizard()
{
	JudgeID::ID _judge = JudgeID::NOTHING;
	if (iter_Note != m_vNote.end())
	{
		if ((*iter_Note).first == MotionID::MOTION_SCRATCHUP)
		{
			if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SCRATCHUP)
			{
				if (m_lDuration < (*iter_Note).second + 10 && m_lDuration >(*iter_Note).second - 10)
				{
					_judge = JudgeID::PERFECT;
				}
				else if (m_lDuration < (*iter_Note).second + 80 && m_lDuration >(*iter_Note).second - 80)
				{
					_judge = JudgeID::GOOD;
				}
				else
				{
					_judge = JudgeID::BAD;
				}
			}
			else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_NULL)
			{
				if(m_lDuration > (*iter_Note).second + 80)
					_judge = JudgeID::BAD;
			}
		}
		else if ((*iter_Note).first == MotionID::MOTION_SCRATCHDOWN)
		{
			if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_SCRATCHDOWN)
			{
				if (m_lDuration < (*iter_Note).second + 10 && m_lDuration >(*iter_Note).second - 10)
				{
					_judge = JudgeID::PERFECT;
				}
				else if (m_lDuration < (*iter_Note).second + 80 && m_lDuration >(*iter_Note).second - 80)
				{
					_judge = JudgeID::GOOD;
				}
				else
				{
					_judge = JudgeID::BAD;
				}
			}
			else if (CMouseMgr::Get_Instance()->Get_Motion() == MotionID::MOTION_NULL)
			{
				if (m_lDuration > (*iter_Note).second + 80)
					_judge = JudgeID::BAD;
			}
		}
	}

	if (iter_Note == m_vNote.end())
		iter_Note == m_vNote.end();
	else
	{
		if (m_lDuration > (*iter_Note).second + 100)
		{
			if (_judge = JudgeID::NOTHING)
				_judge = JudgeID::BAD;
			++iter_Note;
		}
	}

	return _judge;
}

void CScene::Set_Judge()
{
	//판정 적용 부분
	m_eJudge = Judge();
	bool _check = false;
	if (m_eJudge == JudgeID::PERFECT)
	{
		//cout << "PERFECT" << endl;
		CMainPlayer::Get_Instance()->Add_Perfect();
		CMainPlayer::Get_Instance()->Add_Rhythm();
		_check = true;
	}
	else if (m_eJudge == JudgeID::GOOD)
	{
		//cout << "GOOD" << endl;
		CMainPlayer::Get_Instance()->Add_Good();
		CMainPlayer::Get_Instance()->Add_Rhythm();
		_check = true;
	}
	else if (m_eJudge == JudgeID::BAD)
	{
		if (!_check)
		{
			//cout << "BAD" << endl;
			m_tBadTime = system_clock::now();
			++m_iCount;
			CMainPlayer::Get_Instance()->Add_Bad();
			cout << m_iCount << endl;
			m_bReaction = true;
		}
	}
	system_clock::duration _d = duration_cast<milliseconds>(system_clock::now() - m_tBadTime);
	if (_d > (milliseconds)2000)
		m_bReaction = false;
}

void CScene::Set_Lizard_Judge()
{
	//판정 적용 부분
	m_eJudge = Judge_Lizard();
	bool _check = false;
	if (m_eJudge == JudgeID::PERFECT)
	{
		//cout << "PERFECT" << endl;
		CMainPlayer::Get_Instance()->Add_Perfect();
		CMainPlayer::Get_Instance()->Add_Rhythm();
		_check = true;
	}
	else if (m_eJudge == JudgeID::GOOD)
	{
		//cout << "GOOD" << endl;
		CMainPlayer::Get_Instance()->Add_Good();
		CMainPlayer::Get_Instance()->Add_Rhythm();
		_check = true;
	}
	else if (m_eJudge == JudgeID::BAD)
	{
		if (!_check)
		{
			//cout << "BAD" << endl;
			m_tBadTime = system_clock::now();
			++m_iCount;
			CMainPlayer::Get_Instance()->Add_Bad();
			cout << m_iCount << endl;
			m_bReaction = true;
		}
	}
	system_clock::duration _d = duration_cast<milliseconds>(system_clock::now() - m_tBadTime);
	if (_d > (milliseconds)2000)
		m_bReaction = false;
}

void CScene::Set_Note()
{
}
