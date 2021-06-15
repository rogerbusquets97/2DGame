#pragma once
#include "SystemBase.h"

class Application;

class RenderSystem : public SystemBase
{
public:

	RenderSystem(Application& i_app);
	virtual ~RenderSystem();

	bool OnCreate() override;
	bool OnPreUpdate(float fElapsedTime) override;
	bool OnUpdate(float fElapsedTime) override;
	bool OnDestroy() override;

	void SetEnabled(bool i_enabled) override;
	bool IsEnabled() override;
};