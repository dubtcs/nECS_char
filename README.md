# nECS

A simple ECS I use in my [AxtEngine](https://github.com/dubtcs/AxtEngine).

I wanted to try making my own. Once I heard about the idea of an ECS while working on AxtEngine, I really wanted to know how they worked. I think this was a great way to learn.

***This is a learning exercise and should not be used in any serious applications.***

## How to use

All functionality is in namespace axt::ecs

Entities can be referred to as the *ecs::Entity* class on their own or a *ecs::EntityID* managed by the scene.

### Basic Example

Below is a basic example of:

 - Creating an antity
 - Attaching a Transform component with a value of 1.f
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

	sScene.Attach<Transform>(e1, { 1.f });

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
 - (DONE) Attaching components through the Entity itself.
