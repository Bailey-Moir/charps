#pragma once

namespace Charps {
	class GameObject;

	class Component {
	public:
		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		Component(GameObject& gameObject);

		/**
		 * The parent Game Object.
		 */
		GameObject& gameObject;

		/**
		 * The abstracted class of Component, e.g. Transform.
		 */
		void* targetClass;		
	};
}