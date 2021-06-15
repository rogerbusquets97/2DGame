#pragma once
#include "Systems/ISystem.h"

class Application;

class RenderSystem : public ISystem
{
public:

	RenderSystem(const Application& i_app);
	virtual ~RenderSystem();

	bool OnCreate() override;
	bool OnPreUpdate(float fElapsedTime) override;
	bool OnUpdate(float fElapsedTime) override;
	bool OnDestroy() override;

	void SetEnabled(bool i_enabled) override;
	bool IsEnabled() override;
};