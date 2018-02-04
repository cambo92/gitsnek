#include "Snake.h"
#include <assert.h>
#include "Board.h"
#include "Game.h"

Snake::Snake(const Location & loc, bool& go)
{
	segments[0].initHead(loc);
	gameOver = &go;
}

void Snake::moveBy()
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].follow(segments[i - 1]);
	}
	segments[0].moveBy(deltaLoc);

}

void Snake::grow()
{
	if (nSegments < nSegmentsMax)
	{
		nSegments++;
		segments[nSegments - 1].initBody(segments[nSegments - 2].getLoc());
	}
}

void Snake::update(Keyboard & kbd)
{
	if (kbd.KeyIsPressed('W'))
	{
		if (deltaLoc.y != 1)
		{
			deltaLoc = { 0, -1 };
		}
	}
	if (kbd.KeyIsPressed('S'))
	{
		if (deltaLoc.y != -1)
		{
			deltaLoc = { 0, 1 };
		}
	}
	if (kbd.KeyIsPressed('A'))
	{
		if (deltaLoc.x != 1)
		{
			deltaLoc = { -1, 0 };
		}
	}
	if (kbd.KeyIsPressed('D'))
	{
		if (deltaLoc.x != -1)
		{
			deltaLoc = { 1, 0 };
		}
	}
}

void Snake::draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].draw(brd);
	}
}

bool Snake::isColliding(Food f)
{
	if (segments[0].getLoc().isEqualTo(f.getLoc()))
	{
		return true;
	}

	return false;
}

bool Snake::isCollidingSelf()
{
	for (int i = 1; i < nSegments; i++)
	{
		if (segments[0].getLoc().isEqualTo(segments[i].getLoc()))
		{
			return true;
		}
	}
	return false;
}

void Snake::reset()
{
	nSegments = 1;
	segments[0].resetLoc();
}

void Snake::Segment::initHead(const Location & inLoc)
{
	loc = inLoc;
	c = Snake::headColour;
}

void Snake::Segment::initBody(const Location & inLoc)
{
	c = Snake::bodyColour;
	loc = inLoc;
}

void Snake::Segment::follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::moveBy(const Location& deltaLoc)
{
	assert(abs(deltaLoc.x) + abs(deltaLoc.y) == 1);
	loc.add(deltaLoc);
	if (loc.x >= Board::getGridWidth())
	{
		loc.x = 0;
	}
	if (loc.x < 0)
	{
		loc.x = Board::getGridWidth() - 1;
	}
	if (loc.y >= Board::getGridHeight())
	{
		loc.y = 0;
	}
	if (loc.y < 0)
	{
		loc.y = Board::getGridHeight() - 1;
	}
}

void Snake::Segment::draw(Board & brd) const
{
	brd.drawCell(loc, c);
}

Location Snake::Segment::getLoc()
{
	return loc;
}

void Snake::Segment::resetLoc()
{
	loc = locStart;
}
