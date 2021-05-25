#include "stdafx.h"
#include "ObjMgr.h"

IMPLEMENT_SINGLETON(CObjMgr)
CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

CObj * CObjMgr::Get_Target(CObj * pSrc, ObjID::ID eID)
{
	if (m_Objlist[eID].empty())
	{
		return nullptr;
	}
	CObj* pTarget = m_Objlist[eID].front();

	float x = pTarget->Get_Info().fX - pSrc->Get_Info().fX;
	float y = pTarget->Get_Info().fY - pSrc->Get_Info().fY;
	float fDist = sqrtf(x * x + y * y);

	for (auto& pDst : m_Objlist[eID])
	{
		float x2 = pDst->Get_Info().fX - pSrc->Get_Info().fX;
		float y2 = pDst->Get_Info().fY - pSrc->Get_Info().fY;
		float fDist2 = sqrtf(x2 * x2 + y2 * y2);
		if (fDist > fDist2)
		{
			pTarget = pDst;
			fDist = fDist2;
		}
	}
	return pTarget;
}

void CObjMgr::Set_Judge(JudgeID::ID _judge)
{
	for (auto& iter = m_Objlist[ObjID::NPC_REACT].begin(); iter != m_Objlist[ObjID::NPC_REACT].end(); )
	{
		(*iter)->Set_Judge(_judge);
		++iter;
	}
}

void CObjMgr::Set_Reaction(bool _react)
{
	for (auto& iter = m_Objlist[ObjID::NPC_REACT].begin(); iter != m_Objlist[ObjID::NPC_REACT].end(); )
	{
		(*iter)->Set_Reaction(_react);
		++iter;
	}
}

void CObjMgr::Set_Frame(int _Start, int _End, int _Scene)
{
	for (auto& iter = m_Objlist[ObjID::BUTTON_INVENTORY].begin(); iter != m_Objlist[ObjID::BUTTON_INVENTORY].end(); )
	{
		(*iter)->Set_Frame(_Start, _End, _Scene);
		++iter;
	}
}

int CObjMgr::Update()
{
	for (int i = 0; i < ObjID::END; ++i)
	{
		for (auto& iter = m_Objlist[i].begin(); iter != m_Objlist[i].end(); )
		{
			int iEvent = 0;
			iEvent = (*iter)->Update();
			if (iEvent == OBJ_DEAD)
			{
				delete *iter;
				*iter = nullptr;
				iter = m_Objlist[i].erase(iter);
			}
			else
				++iter;
		}
	}
	return OBJ_NOEVENT;
}

void CObjMgr::LateUpdate()
{
	for (int i = 0; i < ObjID::END; ++i)
	{
		for (auto& pObj : m_Objlist[i])
		{
			pObj->LateUpdate();

			if (m_Objlist[i].empty())
				break;
		}
	}
}

void CObjMgr::Render(HDC hdc)
{
	for (int i = 0; i < ObjID::END; ++i)
	{
		for (auto& pObj : m_Objlist[i])
		{
			pObj->Render(hdc);
		}
	}
}

void CObjMgr::Release()
{
	for (int i = 0; i < ObjID::END; ++i)
	{
		for (auto& pObj : m_Objlist[i])
		{
			if (nullptr != pObj)
			{
				delete pObj;
				pObj = nullptr;
			}
		}
		m_Objlist[i].clear();
	}
}

void CObjMgr::AddObject(ObjID::ID eID, CObj * pObj)
{
	m_Objlist[eID].emplace_back(pObj);
}

void CObjMgr::DeleteID(ObjID::ID eID)
{
	for (auto&pObj : m_Objlist[eID])
	{
		Safe_Delete(pObj);
	}
	m_Objlist[eID].clear();
}
