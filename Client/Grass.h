
#include "NPC.h"
class CGrass :
	public CNPC
{
public:
	CGrass();
	virtual ~CGrass();

	// CNPC을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
	virtual void Set_Note() override;
};
