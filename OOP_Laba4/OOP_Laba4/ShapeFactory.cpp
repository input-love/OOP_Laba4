#include "ShapeFactory.h"

Library* ShapeFactory::createShape(int type) 
{
	switch (type)
	{
	case 1:
		return new Vector();
	case 2:
		return new Map();
	}
}