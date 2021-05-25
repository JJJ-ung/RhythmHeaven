#pragma once
#include "Scene.h"
class CCafe :
	public CScene
{
public:
	CCafe();
	virtual ~CCafe();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void Set_Note() override;

public:
	void Render_Text(HDC hDC);
};

