#pragma once
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	// 기본함수
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC _hdc) = 0;
	virtual void Release() = 0;

public:
	// get set
	const INFO& Get_Info()const { return m_tInfo; }
	const RECT& Get_Rect()const { return m_tRect; }
	const FRAME& Get_Frame()const { return m_tFrame; }
	const JudgeID::ID Get_Judge() const { return m_eJudge; }
	const bool Get_Reaction() const { return m_bReaction; }
	void Set_Pos(float fx, float fy)
	{
		m_tInfo.fX = fx;
		m_tInfo.fY = fy;
	}
	void Set_Time(system_clock::time_point _time) { m_tStartTime = _time; }
	void Set_FrameKey(TCHAR* pKey) { m_pFrameKey = pKey; }
	void Set_Judge(JudgeID::ID _judge) { m_eJudge = _judge; }
	void Set_Reaction(bool _react) { m_bReaction = _react; }
	void Set_Frame(int _Start, int _End, int _Scene, long long _Speed, system_clock::time_point _Time)
	{
		m_tFrame.iFrameStart = _Start;
		m_tFrame.iFrameEnd = _End;
		m_tFrame.iFrameScene = _Scene;
		m_tFrame.tFrameSpeed = _Speed;
		m_tFrame.tFrameTime = _Time;
	}
	void Set_Frame(int _Start, int _End, int _Scene)
	{
		m_tFrame.iFrameStart = _Start;
		m_tFrame.iFrameEnd = _End;
		m_tFrame.iFrameScene = _Scene;
	}
	void Set_Number(int i) { m_iNPCNum = i; }
public:
	// 추가함수
	void UpdateRect();
	void FrameMove();
	void FrameStop();

protected:
	INFO m_tInfo;
	RECT m_tRect;
	FRAME m_tFrame;
protected:
	int m_iAlpha;
	BLENDFUNCTION _bf;
protected:
	MotionID::ID m_ePlayerMotion;
	milliseconds m_tCurrentTime;
	milliseconds m_tPlayerTime;
	system_clock::time_point m_tStartTime;
protected:
	int m_iNPCNum;
	TCHAR* m_pFrameKey;
	JudgeID::ID m_eJudge;
	bool m_bReaction;
};

