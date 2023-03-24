#pragma once

#include "Typedef.h"

namespace ecs
{

	extern ComponentTypeID sComponentTypesRegistered;

	template<typename T>
	ComponentTypeID GetComponentTypeID()
	{
		static ComponentTypeID sTypeID{ sComponentTypesRegistered++ };
		return sTypeID;
	}

}
