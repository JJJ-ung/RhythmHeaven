#pragma once
class CMyResource;
class CResourceMgr
{
public:
	DECLARE_SINGLETON(CResourceMgr)
private:
	CResourceMgr();
	~CResourceMgr();
public:
	HDC FindImage(const TCHAR*pImgKey);
	void InsertBmp(const TCHAR*pFilePath, const TCHAR* pImgKey);
	void Release();
private:
	map<const TCHAR*, CMyResource*> m_mapBmp;
};

