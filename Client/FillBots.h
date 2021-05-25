#pragma once
#include "Scene.h"
class CFillBots :
	public CScene
{
public:
	CFillBots();
	virtual ~CFillBots();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	double m_dSpeed;
	MotionID::ID m_eMotion;

	// CScene을(를) 통해 상속됨
	virtual void Set_Note() override;
};

