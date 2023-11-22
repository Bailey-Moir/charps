#pragma once
#include <typeinfo>
#include <vector>

using namespace std;

namespace Charps {
	class GameObject;

	class Component {
	public:
		/**
		 * All the components in the game;
		 */
		static vector<Component*> allComponents;

		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		Component(GameObject& gameObject, const type_info& id);
		~Component();

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
		const type_info& id;
	};
}