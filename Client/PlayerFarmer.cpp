#include "stdafx.h"
#include "PlayerFarmer.h"
#include "ResourceMgr.h"
#include "MouseMgr.h"
#include "StateMachine.h"

CPlayerFarmer::CPlayerFarmer()
{
}


CPlayerFarmer::~CPlayerFarmer()
{
	Safe_Delete(m_pStateMachine);
	Release();
}

void CPlayerFarmer::Initialize()
{
	m_tInfo.fX = 226.f;
	m_tInfo.fY = 235.f;
	m_tInfo.fCX = 348.f;
	m_tInfo.fCY = 412.f;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/BlueBirds_Bird.bmp", L"PlayerBird");

}

int CPlayerFarmer::Update()
{
	return 0;
}

void CPlayerFarmer::LateUpdate()
{
}

void CPlayerFarmer::Render(HDC _hdc)
{
}

void CPlayerFarmer::Release()
{
}
