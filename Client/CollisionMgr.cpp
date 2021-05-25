#include "stdafx.h"
#include "CollisionMgr.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::CheckRect(CObj * pDst, CObj * pSrc, float * pMoveX, float * pMoveY)
{
	float fRadiusSumX = (pDst->Get_Info().fCX * 0.5f) + (pSrc->Get_Info().fCX * 0.5f);
	float fRadiusSumY = (pDst->Get_Info().fCY * 0.5f) + (pSrc->Get_Info().fCY * 0.5f);

	float fDistX = fabs(pDst->Get_Info().fX - pSrc->Get_Info().fX);
	float fDistY = fabs(pDst->Get_Info().fY - pSrc->Get_Info().fY);

	if (fRadiusSumX > fDistX && fRadiusSumY > fDistY)
	{
		*pMoveX = fRadiusSumX - fDistX;
		*pMoveY = fRadiusSumY - fDistY;
		return true;
	}
	return false;
}
