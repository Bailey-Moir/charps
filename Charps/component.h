#pragma once
#include <typeinfo>
#include <vector>

namespace Charps {
	class GameObject;

	class Component {
	public:
		/**
		 * All the components in the game;
		 */
		static std::vector<Component*> allComponents;

		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		Component(GameObject& gameObject, const std::type_info& id);

		/**
		 * The parent Game Object.
		 */
		GameObject& gameObject;

		/**
		 * Called every frame.
		 */
		virtual void update();

		/**
		 * The type of the component derived class.
		 */
		const std::type_info& id;
	};
}