
#include <SDL.h>
#include <stdio.h>
#include <iostream>
using namespace std;


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



bool init();
bool loadMead();
void close();


SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not be initialized!" << endl;
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow(" SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "window could not be created";
			success = false;

		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);

		}


	}

	return success;

	
}

bool loadMedia()
{

	bool success = true;

	
	gHelloWorld = SDL_LoadBMP("Assets/02_getting_an_image_on_the_screen/hello_world.bmp");
	
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Assets/02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}


void close()
{
	
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	
	SDL_Quit();
}

int main(int argc, char* args[])
{
	
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			
			SDL_UpdateWindowSurface(gWindow);
			
			SDL_Delay(2000);
		}
	}

	
	close();

	return 0;
}


