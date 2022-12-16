#include "circlecollider.h"
#include "gameobject.h"

using namespace Charps;

void CircleCollider::checkCollision(const SquareCollider col) {
	#define PC (gameObject.transform.position)
	#define PS (col.gameObject.transform.position)
	#define RC (radius)
	#define RS (col.radius)

	const Vector2<double> diff = PS - PC;
	const Vector2<double> absDiff = diff.absVals();

	Vector2<double> closestSquarePoint;

	bool resolve = false;
	if (absDiff.y <= RS) {
		closestSquarePoint = Vector2<double>(diff.x / absDiff.x * RS, PC.y);
		if (absDiff.x <= RS + RC) resolve = true;
	}
	else if (absDiff.x <= RS) {
		closestSquarePoint = Vector2<double>(PC.x, diff.y / absDiff.y * RS);
		if (absDiff.y <= RS + RC) resolve = true;
	}
	else {
		Vector2<double> direction(diff.x > 0 ? 1 : -1, diff.y > 0 ? 1 : -1);
		closestSquarePoint = PS + direction * RS;
		if ((closestSquarePoint - PC).length() <= RC) resolve = true;
	}
	
	if (resolve) resolveCollision(PC + diff/diff.length() * RC, closestSquarePoint, col);
}

void CircleCollider::checkCollision(const CircleCollider col) {
	#define p (gameObject.transform.position)
	#define p2 (col.gameObject.transform.position)

	const Vector2<double> diff = p2 - p;

	if (diff.length() <= radius + col.radius)
		resolveCollision(p + diff / diff.length() * radius, p2 - diff / diff.length() * col.radius, col);
}
