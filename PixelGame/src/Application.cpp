#define OLC_PGE_APPLICATION
#include "Application.h"
#include "Systems/ISystem.h"

Application::Application(const std::string& i_name)
{
	sAppName = i_name;
}

Application::~Application()
{
	for (auto& system : m_systems)
	{
		delete system;
	}
}

bool Application::OnUserCreate()
{
	bool returnValue = true;
	for (auto& system : m_systems)
	{
		returnValue = system->OnCreate();
	}

	return returnValue;
}

bool Application::OnUserUpdate(float fElapsedTime)
{
	for (auto& system : m_systems)
	{
		if (!system->OnPreUpdate(fElapsedTime))
			return false;
	}

	for (auto& system : m_systems)
	{
		if (!system->OnUpdate(fElapsedTime))
			return false;
	}

	return true;
}

bool Application::OnUserDestroy()
{
	bool returnValue = true;
	for (auto& system : m_systems)
	{
		returnValue = system->OnDestroy();
	}

	return returnValue;
}

void Application::AddSystem(ISystem* i_system)
{
	m_systems.emplace_back(i_system);
}

void Application::RemoveSystem(ISystem* i_system)
{
	auto systemIt = std::find(m_systems.begin(), m_systems.end(), i_system);
	if (systemIt != m_systems.end())
		m_systems.erase(systemIt);
}
