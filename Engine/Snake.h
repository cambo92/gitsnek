#pragma once

#include "Board.h"
#include "Keyboard.h"
#include "Food.h"

class Snake
{
private:
	class Segment
	{
	public:
		void initHead(const Location& loc);
		void initBody(const Location & inLoc);
		void follow(const Segment& next);
		void moveBy(const Location& deltaLoc);
		void draw(Board& brd) const;
		Location getLoc();
		void resetLoc();
	private:
		Location loc;
		Color c;
		Location locStart = {5, 5};
	};

public:
	Snake(const Location& loc, bool& go);
	void moveBy();
	void grow();
	void update(Keyboard& kbd);
	void draw(Board& brd) const;
	bool isColliding(Food f);
	bool isCollidingSelf();
	void reset();

private:
	static constexpr Color headColour = Colors::Yellow;
	static constexpr Color bodyColour = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	Location deltaLoc = { 1, 0 };
	bool gameOver;
	
};