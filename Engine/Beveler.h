#pragma once
#include "Colors.h"
#include "Rect.h"
#include "Graphics.h"

//it remembers a bunch of colors
class Beveler
{
public:
	Beveler(Color baseColor);	
	void DrawOuterBevel(const Rect& rect, int size, Graphics& gfx) const;
	void DrawInnerBevel(const Rect& rect, int size, Graphics& gfx) const;
	void DrawBeveledBrick(Rect& rect, int bevelSize, Graphics& gfx) const;
	void DrawBeveledFrame(Rect& rect, int bevelSize, Graphics& gfx) const;
	Color GetBaseColor() const;
	void SetBaseColor(Color c);
private:
	//the amount of shading (darkness)
	static constexpr float leftFactor = 1.10f;
	static constexpr float topFactor = 0.93f;
	static constexpr float bottomFactor = 0.80f;
	static constexpr float rightFactor = 0.65f;
	Color baseColor;
	Color topColor;
	Color bottomColor;
	Color leftColor;
	Color rightColor;
};