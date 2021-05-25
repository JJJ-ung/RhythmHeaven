#pragma once

template<class T>
class CAbstractFactory
{
public:
	static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}

	static CObj* Create(float fx, float fy)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fx, fy);
		return pObj;
	}

	static CObj* Create(float fx, float fy, float fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fx, fy);
		pObj->Set_Angle(fAngle);
		return pObj;
	}

	static CObj* Create(system_clock::time_point _time)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Time(_time);
		return pObj;
	}

	static CObj* Create(float fx, float fy, system_clock::time_point _time)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fx, fy);
		pObj->Set_Time(_time);
		return pObj;
	}

	static CObj* Create(float fx, float fy, system_clock::time_point _time, int _no)
	{
		CObj* pObj = new T;
		pObj->Set_Number(_no);
		pObj->Initialize();
		pObj->Set_Pos(fx, fy);
		pObj->Set_Time(_time);
		return pObj;
	}
};
