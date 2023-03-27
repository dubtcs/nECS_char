# nECS

A simple ECS I use in my [AxtEngine](https://github.com/dubtcs/AxtEngine).

I wanted to try making my own. Once I heard about the idea of an ECS while working on AxtEngine, I really wanted to know how they worked. I think this was a great way to learn.

***This is a learning exercise and should not be used in any serious applications.***

## How to use

All functionality is in namespace axt::ecs

### Objects

**EntityID** : A uint64_t for identifying entity data.

**Scene** : This controls EntityID distribution, ComponentPack management, and data fetching.

**ComponentPack** : A packed list of data for each entity it's attached to.

**SceneView** : A list of EntityIDs that have components attached to them of the requested type.

**IDManager** : Handles EntityID distrubtion.

### Basic Example

Below is a basic example of:

 - Creating an antity
 - Attaching a Transform component
 - Getting a SceneView of all entities with Transforms
 - Setting the Transform's x variable to 15
 - Deleting the entity

```
	using namespace axt::ecs;

	struct Transform
	{
		float x;
	};

	Scene sScene{};

	EntityID e1{ sScene.CreateEntity() };

	sScene.Attach<Transform>(e1);

	SceneView<Transform> transformView{ sScene };
	for (EntityID id : transformView)
	{
		Transform& trans{ sScene->GetComponent<Transform>(id) };
		trans.x = 15.f;
	}

	sScene.DestroyEntity(e1);
```

## Future

Thinking of adding:
 - Attaching components through the Entity itself.
