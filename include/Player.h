#pragma once

#include "LTexture.h""
#include <SDL.h>
#include <SDL_image.h>

//The dot that will move around on the screen
class Player
{
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 2;

	//Initializes the variables
	Player();

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot
	void move();

	//Shows the dot on the screen
	void render(LTexture &gPlayerTexture, SDL_Renderer* gRenderer);

private:
	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;
};