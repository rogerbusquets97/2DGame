#include "RenderSystem.h"

RenderSystem::RenderSystem(Application& i_app) : SystemBase(i_app)
{
}

RenderSystem::~RenderSystem()
{
}

bool RenderSystem::OnCreate()
{
	return true;
}

bool RenderSystem::OnPreUpdate(float fElapsedTime)
{
	return true;
}

bool RenderSystem::OnUpdate(float fElapsedTime)
{
	return true;
}

bool RenderSystem::OnDestroy()
{
	return true;
}

void RenderSystem::SetEnabled(bool i_enabled)
{
}

bool RenderSystem::IsEnabled()
{
	return true;
}
