#pragma once

class CScene
{
public:
	CScene();
	virtual ~CScene();
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hDC) = 0;
	virtual void Release() = 0;
public:
	void FrameMove();
	void UpdateRect();
	JudgeID::ID Judge();
	JudgeID::ID Judge_Lizard();
	void Set_Judge();
	void Set_Lizard_Judge();
	void Set_Count(int _i) { m_iCount = _i; }
	virtual void Set_Note() = 0;

protected:
	INFO m_tInfo;
	RECT m_tRect;
	FRAME m_tFrame;
protected:
	int m_iAlpha;
	BLENDFUNCTION _bf;
	HWND m_hVideo;
protected:
	system_clock::time_point m_tStartTime;
	long long m_lDuration;
	system_clock::time_point m_tBadTime;
	vector<pair<MotionID::ID, long long>> m_vNote;
	vector<pair<MotionID::ID, long long>>::iterator iter_Note;
	vector<pair<MotionID::ID, long long>>::iterator iter_Next;

	JudgeID::ID m_eJudge;
	bool m_bReaction;
	int m_iCount;
};

