#include "stdafx.h"
#include "ResourceMgr.h"
#include "MyResource.h"

IMPLEMENT_SINGLETON(CResourceMgr)

CResourceMgr::CResourceMgr()
{
}


CResourceMgr::~CResourceMgr()
{
	Release();
}

HDC CResourceMgr::FindImage(const TCHAR * pImgKey)
{
	auto& iter = find_if(m_mapBmp.begin(), m_mapBmp.end(), CStrCmp(pImgKey));
	if (m_mapBmp.end() == iter)
	{
		MessageBox(g_hWND, L"±×¸² ¤¤¤¤¿©!", pImgKey, MB_OK);
		return nullptr;
	}
	return iter->second->Get_MemDC();
}

void CResourceMgr::InsertBmp(const TCHAR * pFilePath, const TCHAR * pImgKey)
{
	auto& iter = find_if(m_mapBmp.begin(), m_mapBmp.end(), [&](auto& rPair)
	{
		return !lstrcmp(pImgKey, rPair.first);
	});

	if (iter == m_mapBmp.end())
	{
		CMyResource* pBitmap = new CMyResource;
		pBitmap->LoadBmp(pFilePath);
		m_mapBmp.emplace(pImgKey, pBitmap);
	}
}

void CResourceMgr::Release()
{
	for (auto& iter : m_mapBmp)
	{
		if (iter.second)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	m_mapBmp.clear();
}
