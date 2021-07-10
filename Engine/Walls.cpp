#include "Walls.h"
#include <assert.h>

Walls::Walls(Rect& innerBounds, float thickness, Color baseColor)
	:
	innerBounds(innerBounds),
	thickness(thickness),
	bev(baseColor)
{
	assert(innerBounds.GetExpanded(thickness).IsContainedBy(Graphics::GetScreenRect()));
}

const Rect& Walls::GetInnerBounds() const
{
	return innerBounds;
}

void Walls::Draw(Graphics& gfx)
{
	bev.DrawBeveledFrame(innerBounds.GetExpanded(thickness), int(thickness) / 2, gfx);
}
