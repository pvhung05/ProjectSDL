#include "Base.h"


using namespace std;


void Base::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

Base::Base()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPosx = 0;
	mPosy = 0;
}

Base::~Base()
{
	free();
}

void Base::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Base::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void Base::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Base::loadfromfile(string path)
{
	free();
	SDL_Surface *image_surface = IMG_Load(path.c_str());
	//SDL_Surface *optimizedSurface = SDL_ConvertSurface(image_surface,image_surface->format,0);
	SDL_SetColorKey(image_surface, SDL_TRUE, SDL_MapRGB(image_surface->format, 0, 0xFF, 0xFF));
	SDL_Texture *image_texture = SDL_CreateTextureFromSurface(grenderer, image_surface);
	mWidth = image_surface->w;
	mHeight = image_surface->h;
	mTexture = image_texture;
	SDL_FreeSurface(image_surface);
}

void Base::setrect(float x, float y)
{
	mPosx = x;
	mPosy = y;
}

void Base::render(SDL_Rect *clip, float angle, SDL_Point *center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { mPosx, mPosy, mWidth, mHeight
	};

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.x = 0;
		renderQuad.y = 0;
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(grenderer, mTexture, clip, &renderQuad, angle, center, flip);

}
