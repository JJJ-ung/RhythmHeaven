#pragma once
#include "Scene.h"
class CBirdOutro :
	public CScene
{
public:
	CBirdOutro();
	virtual ~CBirdOutro();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void Set_Note() override;

private:
	FrameID::ID m_eFrame;
	TCHAR* m_pFrameKey;
};

