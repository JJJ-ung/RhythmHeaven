#pragma once
#include "Obj.h"
class CObjMgr
{
	DECLARE_SINGLETON(CObjMgr)
private:
	CObjMgr();
	~CObjMgr();
public:
	CObj*Get_Target(CObj*pSrc, ObjID::ID eID);
	CObj* Get_Player() { return m_Objlist[ObjID::PLAYER].front(); }
public:
	void Set_Judge(JudgeID::ID _judge);
	void Set_Reaction(bool _react);
	void Set_Frame(int _Start, int _End, int _Scene);
public:
	int Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();
public:
	void AddObject(ObjID::ID eID, CObj*pObj);
	void DeleteID(ObjID::ID eID);
private:
	OBJLIST m_Objlist[ObjID::END];
};

