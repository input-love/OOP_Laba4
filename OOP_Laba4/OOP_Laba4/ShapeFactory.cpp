#include "ShapeFactory.h"

Library* ShapeFactory::createShape(int type) 
{
	if (!type)
	{
		return new Vector();
	}
	else
	{
		return new Map();
	}
}