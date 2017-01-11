#pragma once
#include "Canvas.h"

class ICanvasDrawable
{
public:
	virtual void Draw(ICanvas & canvas) = 0;
};