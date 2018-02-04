#pragma once

struct Location
{
	void add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	bool isEqualTo(const Location& val)
	{
		if (x == val.x && y == val.y)
		{
			return true;
		}
		return false;
	}
	int x;
	int y;
};