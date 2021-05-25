#pragma once
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
public :
	void Initialize();
	void Update();
	void LateUpdate();
	void Render();
	void Release();

private:
	HDC m_hdc;
	int CurrentFrame;
	HFONT hFont, oldFont;

	system_clock::time_point tStart;
	system_clock::time_point tCurrent;
	typedef duration<double, milli> doublemillisec;
	milliseconds  tDuration = (milliseconds) 0;
};

