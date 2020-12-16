#pragma once
#include "Library.h"
#include "Vector.h"
#include "Map.h"

class ShapeFactory {
public:
	Library* createShape(int type);
};