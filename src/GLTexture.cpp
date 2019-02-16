/***************************************************************************
 *   Copyright (C) 2004 by l4t3n8                                          *
 *   mailbockx@freenet.de                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "GLTexture.h"

#include <string>

using namespace std;

//------------------------------------------------------------------------------
GLTexture::GLTexture(const char* file, GLenum target, GLint min_filter, GLint mag_filter)
{
	GLTexture::target   = target;
	GLTexture::min		= min_filter;
	GLTexture::mag		= mag_filter;
	LoadTexture(file);
}

//------------------------------------------------------------------------------
GLTexture::GLTexture(GLenum target, GLint min_filter, GLint mag_filter)
{
	GLTexture::target   = target;
	GLTexture::min		= min_filter;
	GLTexture::mag		= mag_filter;
	GLTexture::pixels	= NULL;
}

//------------------------------------------------------------------------------
void GLTexture::operator = (const GLTexture& t)
{
	if(pixels) free();

	target 	= t.target;		min		= t.min;
	mag		= t.mag;		bpp		= t.bpp;
	width 	= t.width;		height	= t.height;

	pixels = new char[width*height*bpp];
	memcpy(pixels,t.pixels,width*height*bpp);
}

//------------------------------------------------------------------------------
GLTexture::~GLTexture()
{
	if(pixels) free();
}

//------------------------------------------------------------------------------
bool GLTexture::LoadTexture(const char* file)
{
	SDL_Surface* bmp = SDL_LoadBMP(file);

	if(bmp == NULL) return false;

	if(pixels) free();
	
	bpp = bmp->format->BytesPerPixel ;
	width = bmp->w;	height = bmp->h;
	pixels = new char[bpp*width*height];

	if(pixels)
	{
		memcpy(pixels,bmp->pixels,bpp*width*height);
		SDL_FreeSurface(bmp);
	}
	else
	{
		SDL_FreeSurface(bmp);
		return false;
	}

    glGenTextures(1, &texture);
	unsigned char *data = (unsigned char*)pixels;

	for( int i = 0 ; i < (height / 2) ; ++i )
    	for( int j = 0 ; j < width * bpp; j += bpp )
        	for(int k = 0; k < bpp; ++k)
            	swap( data[ (i * width * bpp) + j + k], data[ ( (height - i - 1) * width * bpp) + j + k]);

	return true;
}

//------------------------------------------------------------------------------
void GLTexture::bind()
{
	glBindTexture(target, texture);

	//glTexImage2D(target, 0, 3, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, bmp->pixels);
	gluBuild2DMipmaps(target, 3, width, height, GL_BGR, GL_UNSIGNED_BYTE, pixels);

	glTexParameteri(target,GL_TEXTURE_MIN_FILTER,min);
	glTexParameteri(target,GL_TEXTURE_MAG_FILTER,mag);
}

//------------------------------------------------------------------------------
void GLTexture::free()
{
	if(pixels)
	{
		bpp 	= 0;	width	= 0;		height	= 0;
		delete (char*)pixels;
	}
}

//------------------------------------------------------------------------------
GLuint& GLTexture::Texture()
{
	return texture;
}
