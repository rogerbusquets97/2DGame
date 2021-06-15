#pragma once
#include "olcPixelGameEngine.h"
#include "entt.hpp"

class ISystem;

class Application : public olc::PixelGameEngine
{
public:
	Application(const std::string& i_name);
	virtual ~Application();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;

	void AddSystem(ISystem* i_system);
	void RemoveSystem(ISystem* i_system);

private:
	entt::registry& GetRegistry();

private:

	entt::registry m_registry;
	std::vector<ISystem*> m_systems;

	friend class SystemBase;
};