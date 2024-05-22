#ifndef BASE_H
#define BASE_H
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <fstream>
using namespace std;

class Base
{
	public:
		Base();
	~Base();
	void free();
	void loadfromfile(string path);
	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	//Set blending
	void setBlendMode(SDL_BlendMode blending);
	//Set alpha modulation
	void setAlpha(Uint8 alpha);
	int trang_thai_bat_tat = 0;

	void setrect(float x, float y);
	int hp;

	void render(SDL_Rect *clip = NULL, float angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	float get_pos_x()
	{
		return mPosx;
	};

	float get_pos_y()
	{
		return mPosy;
	};

	float get_width()
	{
		return mWidth;
	};

	float get_height()
	{
		return mHeight;
	};

	void set_hp(int x)
	{
		hp = x;
	};

	protected:
		SDL_Texture * mTexture;
	float mWidth, mHeight, mPosx, mPosy;

};

#endif // BASE_H
