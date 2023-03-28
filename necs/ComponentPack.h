#pragma once

#include "Typedef.h"

#include <ostream>

namespace ecs
{

	using PackIndex = size_t;

	class ComponentPack
	{
	public:
		ComponentPack() = default;
		ComponentPack(size_t elementSize);
		void* Get(const EntityID& id);
		void* Add(const EntityID& id);
		void Remove(const EntityID& id);
	protected:
		Ref<std::vector<char>> mData;
		Ref<std::vector<EntityID>> mIndexToEntity;
		Ref<std::array<PackIndex, gMaxEntities>> mEntityToIndex;
		size_t mElementSize;
		size_t mLength{ 0 };
	};

}
