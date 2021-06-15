#include "RenderSystem.h"
#include "ECS/Components.h"

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
	m_application.Clear({0.0f, 0.0f, 0.0f, 0.0f});

	entt::registry& sceneRegistry = GetSceneRegistry();
	auto& view = sceneRegistry.view<RenderableComponent, TransformComponent>();

	for (auto& entity : view)
	{
		auto[trans, renderable] = view.get<TransformComponent, RenderableComponent>(entity);

		if (m_rendereables.find(renderable.fileName) != m_rendereables.end())
		{
			Rendereable& toRender = m_rendereables.at(renderable.fileName);
			m_application.DrawRotatedDecal({ trans.x, trans.y }, toRender.decal, trans.angle);
		}
	}

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

const RenderSystem::Rendereable& RenderSystem::LoadRendereable(const std::string& i_filePath)
{
	if (m_rendereables.find(i_filePath) == m_rendereables.end())
	{
		olc::Sprite* sprite = new olc::Sprite(i_filePath);
		olc::Decal* decal = new olc::Decal(sprite);

		Rendereable rendereable(i_filePath, sprite, decal);
		m_rendereables.emplace(i_filePath, std::move(rendereable));
	}

	return m_rendereables.at(i_filePath);
}
