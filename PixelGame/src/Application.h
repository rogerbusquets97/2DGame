#pragma once
#include "olcPixelGameEngine.h"
#include "entt.hpp"
#include "ECS/Entity.h"

class ISystem;

class Application : public olc::PixelGameEngine
{
public:
	Application(const std::string& i_name);
	virtual ~Application();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;

	Entity CreateEntity(float x = 0.0f, float y = 0.0f, float angle = 0.0f);

	template<typename T>
	bool AddSystem()
	{
		static_assert(std::is_base_of<ISystem, T>::value, "Added modules must inherit from base class ISystem");
		m_systems.emplace(typeid(T).hash_code(), new T(*this));

		return true;
	}

	template<typename T>
	T* GetSystem()
	{
		static_assert(std::is_base_of<ISystem, T>::value, "Cannot retrieve a non ISystem module!");
		size_t hashCode = typeid(T).hash_code();

		if (m_systems.find(hashCode) != m_systems.end())
		{
			return static_cast<T*>(m_systems.at(hashCode));
		}

		return nullptr;
	}

private:
	entt::registry& GetRegistry();

private:

	entt::registry m_registry;
	std::unordered_map<std::size_t, ISystem*> m_systems;

	friend class SystemBase;
};