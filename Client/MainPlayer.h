#pragma once
class CMainPlayer
{
	DECLARE_SINGLETON(CMainPlayer)
private:
	CMainPlayer();
	~CMainPlayer();

public:
	void Initialize();

public:
	MEDALS* Get_BirdMedal() { return &m_tBirds; }
	MEDALS* Get_LizardMedal() { return &m_tLizard; }
	MEDALS* Get_FanClubMedal() { return &m_tFanClub; }

public:
	void Set_Perfect_Medal();
	void Set_Superb_Medal();
	void Set_OK_Medal();
	void Set_Null_Medal();
	void Set_All_Medal();

public:
	void Set_Bird_Perfect() { m_tBirds.PerfectMedal = true; }
	void Set_Bird_Superb() { m_tBirds.SuperbMedal = true; }
	void Set_Bird_OK() { m_tBirds.OKMedal = true; }
	void Set_Bird_Null() { m_tBirds.NullMedal = true; }

public:
	void Set_FanClub_Perfect() { m_tFanClub.PerfectMedal = true; }
	void Set_FanClub_Superb() { m_tFanClub.SuperbMedal = true; }
	void Set_FanClub_OK() { m_tFanClub.OKMedal = true; }
	void Set_FanClub_Null() { m_tFanClub.NullMedal = true; }

public:
	void Set_Lizard_Perfect() { m_tLizard.PerfectMedal = true; }
	void Set_Lizard_Superb() { m_tLizard.SuperbMedal = true; }
	void Set_Lizard_OK() { m_tLizard.OKMedal = true; }
	void Set_Lizard_Null() { m_tLizard.NullMedal = true; }

public:
	void Add_Perfect() { ++m_iPerfect; }
	void Add_Good() { ++m_iGood; }
	void Add_Bad() { ++m_iBad; }
	void Add_Rhythm() { Rhythm_Stat += rand() % 10; }
	int Get_Rhythm() { return Rhythm_Stat; }
	int Get_Perfect_Count() { return m_iPerfect; }
	int Get_Good_Count() { return m_iGood; }
	int Get_Bad_Count() { return m_iBad; }

public:
	int Get_Bird_Count() { return m_iBirdCount; }
	int Get_Fan_Count() { return m_iFanCount; }
	int Get_Lizard_Count() { return m_iLizardCount; }
	void Add_Bird_Count() { ++m_iBirdCount; }
	void Add_Lizard_Count() { ++m_iLizardCount; }
	void Add_Fan_Count() { ++m_iFanCount; }

private:
	int m_iPerfect;
	int m_iGood;
	int m_iBad;
	int Rhythm_Stat;
	MEDALS m_tBirds;
	MEDALS m_tLizard;
	MEDALS m_tFanClub;
	int m_iBirdCount;
	int m_iFanCount;
	int m_iLizardCount;
};

