#pragma once
class CSoundMgr
{
	DECLARE_SINGLETON(CSoundMgr)
private:
	CSoundMgr(void);
public:
	~CSoundMgr(void);

public:
	enum CHANNEL_ID { BGM, PLAYER, NPC, EFFECT, UI, END };

public:
	void Initialize();
	void Update();
	void PlaySound(const string& strSoundKey, CHANNEL_ID eID);
	void PlayBGM(const string& strSoundKey);
	void StopSound(CHANNEL_ID eID);
	void StopAll();

private:
	void LoadSoundFile();
	void Release();

private:
	FMOD_SYSTEM*				m_pSystem;	// ���� ��ġ�� �����ϴ� �ý��� ����ü.
	FMOD_CHANNEL*				m_pChannel[END]; // ���� ���带 ����� ä��.
	map<string, FMOD_SOUND*>	m_mapSound;

};