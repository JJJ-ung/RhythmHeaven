#pragma once
#include "Scene.h"
class COpeningUI :
	public CScene
{
public:
	COpeningUI();
	virtual ~COpeningUI();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	// CScene��(��) ���� ��ӵ�
	virtual void Set_Note() override;

};

