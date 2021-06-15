#pragma once
#include "entt.hpp"

class Entity
{
public:
	
	Entity(entt::entity i_handle, entt::registry& i_registry) : m_handle(i_handle), m_sceneRegistry(i_registry){};
	Entity(const Entity& i_other) = default;

	template<typename T, typename... Args>
	T& AddComponent(Args&& ... args)
	{
		return m_sceneRegistry.emplace<T>(m_handle, std::forward<Args>(args)...);
	}

	template<typename T>
	T& GetComponent()
	{
		return m_sceneRegistry.get<T>(m_handle);
	}

	template<typename T>
	bool HasComponent()
	{
		return m_sceneRegistry.has<T>(m_handle);
	}

	operator bool() const { return m_handle != entt::null; }
	bool operator==(const Entity& other) const { return m_handle == other.m_handle && &m_sceneRegistry == &other.m_sceneRegistry; }
	bool operator!=(const Entity& other) const { return !(*this == other); }
	bool IsValid() const { return m_handle != entt::null; }

	entt::entity GetHandle() const { return m_handle; }

private:

	entt::registry& m_sceneRegistry;
	entt::entity m_handle{ entt::null };
};