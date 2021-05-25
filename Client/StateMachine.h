#pragma once
#include "stdafx.h"
#include "State.h"
template<class T>
class StateMachine
{
	State<T>* m_pCurrentState;
	T*m_pOwner;
public:
	StateMachine(T* owner)
		:m_pOwner(owner)
		,m_pCurrentState(NULL)
	{}

	void Update()
	{
		m_pCurrentState->Execute(m_pOwner);
	}
	void ChangeState(State<T>*pState)
	{
		m_pCurrentState->Exit(m_pOwner);
		m_pCurrentState = pState;
		m_pCurrentState->Enter(m_pOwner);
	}

	State<T>*GetCurrentState() { return this->m_pCurrentState; }
	void SetCurrentState(State<T>*pState) { m_pCurrentState = pState;}
};
