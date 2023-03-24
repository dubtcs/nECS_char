# nECS

A lightweight ECS I use in my [AxtEngine](https://github.com/dubtcs/AxtEngine).

### But why?

I wanted to try making my own. Once I heard about the idea of an ECS while working on AxtEngine, I really wanted to know how they worked. I think this was a great way to learn.

## Getting started

- Clone the repository using `git clone https://github.com/dubtcs/AxtEngine.git`

- Add the `include` folder to your compilers additional include directories

## How to use

All functionality is in namespace axt::ecs

Below is a basic example of workflow with nECS

    using namespace axt::ecs;

	struct Transform
	{
		float x;
	};
	struct Color
	{
		float x;
	};

	ecs::Scene sScene{};

    // Create from the scene. It will return an EntityID.
    // This ID is what you use to access data relating to the entity.
	EntityID e1{ sScene.CreateEntity() };

    // Attach a component to an entity.
    // No registering the component required, just attach it and the system will make it work.
	sScene.Attach<Transform>(e1);
	sScene.Attach<Color>(e1);

    // Remove a component from the entity
	sScene.Detach<Transform>(e1);

    // Destroy an entity and all components relating to it
	sScene.DestroyEntity(e1);

