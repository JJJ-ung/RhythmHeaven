#pragma once

#define WINCX 800
#define WINCY 600

#define OBJ_DEAD 1
#define OBJ_NOEVENT 0

#define DECLARE_SINGLETON(ClassName)		\
public:										\
	static ClassName* Get_Instance()		\
	{										\
		if (nullptr == m_pInstance)			\
			m_pInstance = new ClassName;	\
											\
		return m_pInstance;					\
	}										\
	static void Destroy_Instance()			\
	{										\
		if (m_pInstance)					\
		{									\
			delete m_pInstance;				\
			m_pInstance = nullptr;			\
		}									\
	}										\
private:									\
	static ClassName* m_pInstance;


#define IMPLEMENT_SINGLETON(ClassName)			\
ClassName* ClassName::m_pInstance = nullptr;	

#define D_CAST(className, Obj) dynamic_cast<className*>(Obj)

#define SQUARE(x) x*x

#define POINT_UP true
#define POINT_DOWN false