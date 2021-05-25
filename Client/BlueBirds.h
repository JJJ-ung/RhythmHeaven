#pragma once
#include "Scene.h"
class CBlueBirds :
	public CScene
{
public:
	CBlueBirds();
	~CBlueBirds();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	// CScene을(를) 통해 상속됨
	virtual void Set_Note() override;

};

