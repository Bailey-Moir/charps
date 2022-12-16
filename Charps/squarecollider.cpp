#include "squarecollider.h"
#include "gameobject.h"

void Charps::SquareCollider::checkCollision(const SquareCollider col) {
	#define p (gameObject.transform.position)
	#define p2 (col.gameObject.transform.position)
	const Vector2<double> diff = p2 - p;
	const float totalRadius = radius + col.radius;

	if (abs(diff.x) <= totalRadius && abs(diff.y) <= totalRadius) {
		Vector2<double> direction(diff.x > 0 ? 1 : -1, diff.y > 0 ? 1 : -1);
		resolveCollision(p - direction * radius, p2 + direction * col.radius, col);
	}
}

void Charps::SquareCollider::checkCollision(const CircleCollider col) {
	#define PC (col.gameObject.transform.position)
	#define PS (gameObject.transform.position)
	#define RC (col.radius)
	#define RS (radius)

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

	if (resolve) resolveCollision(closestSquarePoint, PC + diff / diff.length() * RC, col);
}
