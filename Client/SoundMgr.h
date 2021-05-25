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
	FMOD_SYSTEM*				m_pSystem;	// 사운드 장치를 제어하는 시스템 구조체.
	FMOD_CHANNEL*				m_pChannel[END]; // 실제 사운드를 재생할 채널.
	map<string, FMOD_SOUND*>	m_mapSound;

};