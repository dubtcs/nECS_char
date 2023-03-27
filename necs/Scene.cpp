
#include "Scene.h"

namespace ecs
{

	Scene::Scene()
	{
		mPacks = NewRef<std::vector<ComponentPack>>();
		mEntityInfo = NewRef<std::array<EntityInfo, gMaxEntities>>();
	}

	EntityID Scene::CreateEntity()
	{
		EntityID r{ mIDManager.Create() };
		mEntityInfo->at(r).ID = r;
		return r;
	}

	void Scene::DestroyEntity(const EntityID& id)
	{
		// remove the data from each pack it belongs to
		// reset the mask
		for (ComponentPack& pack : *mPacks)
		{
			pack.Remove(id);
		}
		mEntityInfo->at(id).Mask.reset();
		mIDManager.Remove(id);
	}

	Ref<std::array<Scene::EntityInfo, gMaxEntities>> Scene::GetEntityInfo()
	{
		return mEntityInfo;
	}

	const IDManager& Scene::GetIDManager() const
	{
		return mIDManager;
	}

}