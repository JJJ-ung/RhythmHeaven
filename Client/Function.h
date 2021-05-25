#pragma once
class CStrCmp
{
public:
	CStrCmp() {};
	CStrCmp(const TCHAR* pString)
		:m_pString(pString)
	{}
	~CStrCmp() {};
public:
	template<typename T>
	bool operator()(T& rPair)
	{
		return !lstrcmp(m_pString, rPair.first);
	}
private:
	const TCHAR* m_pString;

};

template<typename T>
void Safe_Delete(T& rObj)
{
	if (rObj)
	{
		delete rObj;
		rObj = nullptr;
	}
}