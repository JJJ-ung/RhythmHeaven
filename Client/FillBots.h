#pragma once
#include "Scene.h"
class CFillBots :
	public CScene
{
public:
	CFillBots();
	virtual ~CFillBots();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	double m_dSpeed;
	MotionID::ID m_eMotion;

	// CScene��(��) ���� ��ӵ�
	virtual void Set_Note() override;
};

