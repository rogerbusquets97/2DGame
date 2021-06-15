#pragma once
#include "ECS/Systems/SystemBase.h"

class Application;

class GUISystem : public SystemBase
{
public:
	GUISystem(Application& i_app);
	virtual ~GUISystem();

	bool OnCreate() override;
	bool OnPreUpdate(float fElapsedTime) override;
	bool OnUpdate(float fElapsedTime) override;
	bool OnDestroy() override;

	void SetEnabled(bool i_enabled) override;
	bool IsEnabled() override;
};