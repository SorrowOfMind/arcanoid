#pragma once

#include "Rect.h"
#include "Beveler.h"
#include "Graphics.h"

class Walls
{
public:
	Walls(Rect& innerBounds, float thickness, Color baseColor);
	const Rect& GetInnerBounds() const;
	void Draw(Graphics& gfx);
private:
	Rect innerBounds;
	float thickness;
	Beveler bev;
};