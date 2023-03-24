#pragma once

#include <axt/Core.h>

#include "Scene.h"
#include "ComponentPack.h"

namespace axt::ecs
{

	template<typename... T>
	class AXT_API SceneView
	{
	public:
		SceneView(Ref<Scene>&scene) : mScene{ scene }
		{
			ComponentTypeID ids[]{ GetComponentTypeID<T>()... };
			for (uint32_t i{ 0 }; i < sizeof...(T); i++)
			{
				mSignature.set(ids[i]);
			}
		}
	public:
		class iterator
		{
			using iterator_category = std::forward_iterator_tag;
			using difference_type = std::ptrdiff_t;
			using value_type = ComponentPack;
			using pointer = ComponentPack*;
			using reference = ComponentPack&;

			//EntityID operator*() const;
			/*bool operator--(const iterator& other) const;
			bool operator!=(const iterator& other) const;*/
			//iterator& operator++();
		};
		//const iterator begin() const;
		//const iterator end() const;
	protected:
		Ref<Scene> mScene;
		Signature mSignature;
	};

}
