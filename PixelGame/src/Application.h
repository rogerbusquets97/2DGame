#pragma once
#include "olcPixelGameEngine.h"

class ISystem;

class Application : public olc::PixelGameEngine
{
public :
	Application(const std::string& i_name);
	virtual ~Application();
	
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;

	void AddSystem(ISystem* i_system);
	void RemoveSystem(ISystem* i_system);

private:

	std::vector<ISystem*> m_systems;
};