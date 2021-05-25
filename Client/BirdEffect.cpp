#include "stdafx.h"
#include "BirdEffect.h"
#include "ResourceMgr.h"


CBirdEffect::CBirdEffect()
{
}


CBirdEffect::~CBirdEffect()
{
}

void CBirdEffect::Initialize()
{
	Set_Note();
	iter_NPCNote = m_vNPCNote.begin();

	m_tInfo.fCX = 400.f;
	m_tInfo.fCY = 245.f;
	m_tInfo.fX = 200.f;
	m_tInfo.fY = 127.5f;

	m_iAlpha = 0;
	m_iAmount = 0;

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iFrameScene = 0;

	CResourceMgr::Get_Instance()->InsertBmp(L"../Image/BlueBirds/HweSang.bmp", L"HweSang");
}

int CBirdEffect::Update()
{
	milliseconds _time = duration_cast<milliseconds>(system_clock::now() - m_tStartTime);
	if (iter_NPCNote != m_vNPCNote.end())
	{
		if ((_time.count() > (*iter_NPCNote).second - 50) && _time.count() < (*iter_NPCNote).second + 50)
		{
			if ((*iter_NPCNote).first == FADE_IN)
			{
				//if (m_iAlpha < 255)
					m_iAmount = 7;
			}
			else if ((*iter_NPCNote).first == QUICK_FADE_IN)
			{
				//if (m_iAlpha < 255)
				m_iAmount = 20;
			}
			else if ((*iter_NPCNote).first == FADE_OUT)
			{
				//if (m_iAlpha > 0)
				m_iAmount = -7;
			}
			else if ((*iter_NPCNote).first == QUICK_FADE_OUT)
			{
				//if (m_iAlpha > 0)
				m_iAmount = -20;
			}
			else if ((*iter_NPCNote).first == OUT_SCREEN)
			{
				m_iAlpha = 0;
			}
			else if ((*iter_NPCNote).first == ON_SCREEN)
			{
				m_iAlpha = 255;
			}
			else if ((*iter_NPCNote).first == ADD)
			{
				m_tFrame.iFrameStart += 1;
				m_tFrame.iFrameEnd += 1;
			}
			++iter_NPCNote;
		}
	}

	return 0;
}


void CBirdEffect::LateUpdate()
{
	m_iAlpha += m_iAmount;
	if (m_iAlpha < 0)
		m_iAlpha = 0;
	if (m_iAlpha > 255)
		m_iAlpha = 255;
	CObj::UpdateRect();
}

void CBirdEffect::Render(HDC _hdc)
{
	HDC hMemDC = CResourceMgr::Get_Instance()->FindImage(L"HweSang");

	_bf.BlendOp = 0;
	_bf.BlendFlags = 0;
	_bf.SourceConstantAlpha = 0 + m_iAlpha;
	_bf.AlphaFormat = AC_SRC_OVER;
	GdiAlphaBlend(_hdc, m_tRect.left, m_tRect.top,
		m_tInfo.fCX, m_tInfo.fCY, hMemDC,
		m_tFrame.iFrameStart * m_tInfo.fCX, m_tFrame.iFrameScene * m_tInfo.fCY,
		m_tInfo.fCX, m_tInfo.fCY, _bf);
}

void CBirdEffect::Release()
{
}

void CBirdEffect::Set_Note()
{
	//1번
	m_vNPCNote.emplace_back(FADE_IN, 24546);
	m_vNPCNote.emplace_back(ON_SCREEN, 25546);
	m_vNPCNote.emplace_back(FADE_OUT, 29083);
	m_vNPCNote.emplace_back(OUT_SCREEN, 30083);

	m_vNPCNote.emplace_back(ADD, 30583);

	//2번
	m_vNPCNote.emplace_back(FADE_IN, 31920);
	m_vNPCNote.emplace_back(ON_SCREEN, 32920);
	m_vNPCNote.emplace_back(FADE_OUT, 36461);
	m_vNPCNote.emplace_back(OUT_SCREEN, 37461);

	m_vNPCNote.emplace_back(ADD, 37983);

	//3번
	m_vNPCNote.emplace_back(FADE_IN, 40214);
	m_vNPCNote.emplace_back(ON_SCREEN, 41214);
	m_vNPCNote.emplace_back(FADE_OUT, 43670);
	m_vNPCNote.emplace_back(OUT_SCREEN, 44670);

	m_vNPCNote.emplace_back(ADD, 45170);

	//4번
	m_vNPCNote.emplace_back(QUICK_FADE_IN, 50402);
	m_vNPCNote.emplace_back(ON_SCREEN, 50902);
	m_vNPCNote.emplace_back(QUICK_FADE_OUT, 51491);
	m_vNPCNote.emplace_back(OUT_SCREEN, 51991);

	m_vNPCNote.emplace_back(ADD, 52000);

	//5번
	m_vNPCNote.emplace_back(QUICK_FADE_IN, 52242);
	m_vNPCNote.emplace_back(ON_SCREEN, 52742);
	m_vNPCNote.emplace_back(QUICK_FADE_OUT, 53359);
	m_vNPCNote.emplace_back(OUT_SCREEN, 53859);

	m_vNPCNote.emplace_back(ADD, 53990);

	//6번
	m_vNPCNote.emplace_back(QUICK_FADE_IN, 54091);
	m_vNPCNote.emplace_back(ON_SCREEN, 54591);
}
