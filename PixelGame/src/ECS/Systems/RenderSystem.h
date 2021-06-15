#pragma once
#include "SystemBase.h"

namespace olc
{
	class Sprite;
	class Decal;
}

class Application;

class RenderSystem : public SystemBase
{
public:

	struct Rendereable
	{
		std::string fileName;
		olc::Sprite* sprite;
		olc::Decal* decal;

		Rendereable(std::string i_fileName, olc::Sprite* const i_sprite, olc::Decal* const i_decal) : fileName(i_fileName), sprite(i_sprite), decal(i_decal)
		{
		}
	};

public:
	RenderSystem(Application& i_app);
	virtual ~RenderSystem();

	bool OnCreate() override;
	bool OnPreUpdate(float fElapsedTime) override;
	bool OnUpdate(float fElapsedTime) override;
	bool OnDestroy() override;

	void SetEnabled(bool i_enabled) override;
	bool IsEnabled() override;

	const Rendereable& LoadRendereable(const std::string& i_filePath);

private:

	std::unordered_map<std::string, Rendereable> m_rendereables;
};