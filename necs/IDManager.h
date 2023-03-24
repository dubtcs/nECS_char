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
	protected:
		std::stack<EntityID> mStack;
		uint32_t mIdsUsed;
	};

}
