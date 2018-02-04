#pragma once

#include "Board.h"
#include "Colors.h"
#include "Location.h"
#include <random>

class Food
{
public:
	Food();
	void jump();
	void update();
	void draw(Board brd) const;
	Location getLoc();

private:
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	static constexpr Color colour = Colors::Red;
	Location loc;

	class Effect
	{
	public:
		void update

	private:
		int x, y, w, h;
		int red = 255;
		int age = 0;
	};
};