#define OLC_PGE_APPLICATION
#include "Application.h"
#include "ECS/Systems/ISystem.h"
#include "ECS/Systems/RenderSystem.h"
#include "ECS/Components.h"

Application::Application(const std::string& i_name)
{
	sAppName = i_name;

	AddSystem<RenderSystem>();
}

Application::~Application()
{
	for (auto& system : m_systems)
	{
		delete system.second;
	}
}

bool Application::OnUserCreate()
{
	bool returnValue = true;
	for (auto& system : m_systems)
	{
		returnValue = system.second->OnCreate();
	}

	return returnValue;
}

bool Application::OnUserUpdate(float fElapsedTime)
{
	for (auto& system : m_systems)
	{
		if (!system.second->OnPreUpdate(fElapsedTime))
			return false;
	}

	for (auto& system : m_systems)
	{
		if (!system.second->OnUpdate(fElapsedTime))
			return false;
	}

	return true;
}

bool Application::OnUserDestroy()
{
	bool returnValue = true;
	for (auto& system : m_systems)
	{
		returnValue = system.second->OnDestroy();
	}

	return returnValue;
}

Entity Application::CreateEntity(float x, float y, float angle)
{
	entt::entity handle = m_registry.create();
	TransformComponent trans;

	Entity ent(handle, m_registry);
	ent.AddComponent<TransformComponent>(x, y, angle);
	return ent;
}

entt::registry& Application::GetRegistry()
{
	return m_registry;
}
