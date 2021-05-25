#pragma once
#include "Obj.h"
class CNPC :
	public CObj
{
public:
	CNPC();
	virtual ~CNPC();
	virtual void Set_Note() = 0;

protected:	
//	TCHAR* m_pFrameKey;
};

