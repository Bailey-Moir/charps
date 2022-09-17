#pragma once
#include "component.h"
#include "transform.h"
#include <vector>

namespace Charps {
	class Window;

	/**
	 * Represents a Game Object.
	 */
	class GameObject {
	private:
		/**
		 * All the components on the Game Object
		 */
		std::vector<void*> components = std::vector<void*>();

	public:
		/**
		 * Constructor.
		 * @paran window The window the Game Object is rendered on.
		 */
		GameObject(Window& window);

		/**
		 * The window the Game Object is rendered on.
		 */
		Window& window;
		/**
		 * The transform of the Game Object.
		 */
		Transform transform;

		/**
		 * Attempts go get a component from the Game Object.
		 * @return Pointer to component. If component not found, returns nullptr.
		 */
		template<typename T>
		T* getComponent();

		/**
		 * Attempts to add a component to the Game Object.
		 * 
		 */
		void addComponent(void* component);
	};

	template<typename T>
	T* GameObject::getComponent() {
		/**
		 * Define this. 
		 */
		return nullptr;
	}
}
