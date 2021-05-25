#include "stdafx.h"
#include "Medal.h"
#include "ResourceMgr.h"

CMedal::CMedal()
{
}


CMedal::~CMedal()
{
}

void CMedal::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 58.f;
	//m_tFrame.iFrameScene = 0;
	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/Cafe/Cafe_Medal_2.bmp", L"CafeMedal");
}

int CMedal::Update()
{
	return OBJ_NOEVENT;
}

void CMedal::LateUpdate()
{
	CObj::UpdateRect();
}

void CMedal::Render(HDC _hdc)
{
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"CafeMedal");
	GdiTransparentBlt(_hdc,
		m_tRect.left, m_tRect.top,
		m_tInfo.fCX, m_tInfo.fCY,
		hMemDC,
		m_tFrame.iFrameStart * m_tInfo.fCX, m_tFrame.iFrameScene * m_tInfo.fCY,// 출력할 그림의 시작 좌표. 
		m_tInfo.fCX, m_tInfo.fCY,//그림의 전체 가로세로 크기 
		RGB(255, 0, 255));
}

void CMedal::Release()
{
}
