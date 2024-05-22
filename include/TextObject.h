#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H
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
#include "Base.h"
using namespace std;

class TextObject: public Base
{
	public: enum TextColor
	{
		RED_TEXT = 0,
			WHITE_TEXT = 1,
			BLACK_TEXT = 2,
	};

	TextObject();~TextObject();
	void Set_Text(string path1);
	void Set_Color(int type);
	void loadFromRenderedText();
	void Show_Text()
	{
		cout << text;
	};

	private: string text;
	SDL_Color text_color;
};

#endif // TEXTOBJECT_H
