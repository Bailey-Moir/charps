#pragma once
#include <typeinfo>

namespace Charps {
	class GameObject;

	class Component {
	public:
		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		Component(GameObject& gameObject, const std::type_info& id);

		/**
		 * The parent Game Object.
		 */
		GameObject& gameObject;

		virtual void update();

		const std::type_info& id;
	};
}