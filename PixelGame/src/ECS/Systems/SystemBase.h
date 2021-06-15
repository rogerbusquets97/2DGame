#pragma once
#include "ISystem.h"
#include "Application.h"

class SystemBase : public ISystem
{
public:
	SystemBase(Application& i_application) : m_application(i_application){};
	
	entt::registry& GetSceneRegistry()
	{
		return m_application.GetRegistry();
	}

protected:
	Application& m_application;
};