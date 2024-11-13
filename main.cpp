#include <stdio.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {

	Circle circle;
	circle.Draw();

	Rectangle rectangle;
	rectangle.Draw();

	return 0;
}