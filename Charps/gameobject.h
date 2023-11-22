#pragma once
#include "component.h"
#include "transform.h"
#include <typeinfo>
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
		std::vector<Component*> components = std::vector<Component*>();

	public:
		/**
		 * Creates a GameObject on the current window context.
		 * @param window The window the Game Object is rendered on.
		 */
		GameObject();

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
		void addComponent(Component* component);
		void removeComponent(Component* component);
	};

	template<typename T>
	T* GameObject::getComponent() {
		for (int i = 0; i < components.size(); i++) {
			// if is never true
			if (typeid(T) == components[i]->id) {
				return dynamic_cast<T*>(components[i]);
			}
		}
	}
}
