#pragma once
#include "Scene.h"
class CCropStomp :
	public CScene
{
public:
	CCropStomp();
	virtual ~CCropStomp();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	// CScene��(��) ���� ��ӵ�
	virtual void Set_Note() override;

};

