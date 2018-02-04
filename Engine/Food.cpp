#include "Food.h"

Food::Food()
	:
	rng(std::random_device()()),
	xDist(0, Board::getGridWidth() - 1),
	yDist(0, Board::getGridHeight() - 1)
{
	jump();
}

void Food::jump()
{
	loc = { xDist(rng), yDist(rng)};
}

void Food::update()
{
}

void Food::draw(Board brd) const
{
	brd.drawCell(loc, colour);
}

Location Food::getLoc()
{
	return loc;
}
