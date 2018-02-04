#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::drawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.drawRectDim(loc.x * dimension + ox + 1, loc.y * dimension + oy + 1, dimension - 2, dimension - 2, c);
}

void Board::drawBorder()
{
	gfx.drawRectOutline(ox, oy, ox + dimension * width, oy + dimension * height);
}

int Board::getGridWidth()
{
	return width;
}

int Board::getGridHeight() 
{
	return height;
}
