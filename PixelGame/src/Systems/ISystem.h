#pragma once

class ISystem
{
public:

	virtual bool OnCreate() = 0;
	virtual bool OnPreUpdate(float fElapsedTime) = 0;
	virtual bool OnUpdate(float fElapsedTime) = 0;
	virtual bool OnDestroy() = 0;
	virtual void SetEnabled(bool i_enabled) = 0;
	virtual bool IsEnabled() = 0;
};