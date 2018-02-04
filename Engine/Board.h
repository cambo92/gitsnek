#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void drawCell(const Location& loc, Color c);
	void drawBorder();
	static int getGridWidth();
	static int getGridHeight();

private:
	static constexpr int dimension = 20;
	static constexpr int width = 36;
	static constexpr int height = 26;
	static constexpr int ox = 40;
	static constexpr int oy = 40;
	Graphics& gfx;
};