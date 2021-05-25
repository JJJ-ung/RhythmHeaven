#pragma once
class CMyResource
{
public:
	CMyResource();
	~CMyResource();

public:
	HDC Get_MemDC() { return m_hMemDC; }
	void LoadBmp(const TCHAR*pFilePath);
	void Release();

private:
	HDC m_hMemDC;
	HBITMAP m_hBitmap;
	HBITMAP m_hOldBitmap;
};

