#pragma once
#include"Obj.h"
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();
public:
	static bool CheckRect(CObj* pDst, CObj* pSrc, float* pMoveX, float* pMoveY);
};

