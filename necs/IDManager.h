#pragma once

#include "Typedef.h"

#include <stack>

namespace ecs
{

	class IDManager
	{
	public:
		EntityID Create();
		void Remove(const EntityID& id);
		IDManager();
	public:
		const std::vector<EntityID>::const_iterator begin() const { return mIdsUsed.begin(); }
		const std::vector<EntityID>::const_iterator end() const { return mIdsUsed.end(); }
	protected:
		std::stack<EntityID> mStack;
		uint32_t mIdsUsed;
	};

}
