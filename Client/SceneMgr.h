#pragma once
class CScene;
class CSceneMgr
{
	DECLARE_SINGLETON(CSceneMgr)
private:
	CSceneMgr();
	~CSceneMgr();
public:
	enum SCENEID {	SCENE_OPENING, SCENE_MENU, 
					INTRO_BIRDS, INTRO_FARM, INTRO_LIZARDS, INTRO_FANCLUB,
					SCENE_FILLBOTS, SCENE_BIRDS, SCENE_FARM, SCENE_LIZARDS, SCENE_FANCLUB, 
					OUTRO_BIRDS, OUTRO_FARM, OUTRO_LIZARDS, OUTRO_FANCLUB,
					SCENE_CAFE,
					SCENE_END };
public:
	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();
public:
	void SceneChange(SCENEID eScene);
	void SceneChange(SCENEID eScene, int _i);
	const SCENEID Get_SceneID() { return m_eCurScene; }

private:
	CScene* m_pScene;
	SCENEID m_eCurScene;
	SCENEID m_eNextScene;
};

