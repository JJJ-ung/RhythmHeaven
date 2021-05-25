#pragma once
class CMouseMgr
{
	DECLARE_SINGLETON(CMouseMgr)
private:
	CMouseMgr();
	~CMouseMgr();
public:
	void Initialize(SceneID::ID _scene);
	void Update();
	void LateUpdate();
	void Render(HDC _hdc);
	void Release();
public:
	const MotionID::ID Get_Motion()const { return m_eMotion; };
	const double Get_Speed() const { return m_dSpeed; }
	const long long Get_PressTime() const { return m_tPressTime.count(); }
	const bool Get_Lizard_Check() const { return m_bLizardCheck; }
	void Set_Speed(double _speed) { m_dSpeed = _speed; }
	enum Scratch { NO_EVENT, UP_1, UP_2, DOWN_1, DOWN_2 };
private:
	void Update_Rect();
	void Sound_KeyDown();
	void Sound_KeyUp();
	void Sound_Slide();
private:
	MotionID::ID m_eMotion;
	INFO m_tInfo;
	RECT m_tRect;
	FRAME m_tFrame;
	SceneID::ID m_eScene;
private:
	double m_dSpeed;
	double m_dStart;
	double m_dEnd;
	double m_dCurrent;
	POINT m_pStart = {};
	POINT m_pCurrent = {};
	POINT m_pEnd = {};
	milliseconds m_tPressTime;
	system_clock::time_point m_tPressStart;
private:
	void Set_Lizard();
	void Change_State(Scratch _event);
	bool m_bLizardCheck;
	int m_iRandonSound;
	Scratch m_eCurState;
	Scratch m_eNextState;
};

