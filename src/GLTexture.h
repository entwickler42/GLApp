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
#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "SDL.h"
#include <GL/gl.h>
#include <GL/glu.h>

//------------------------------------------------------------------------------
inline void swap(unsigned char & a, unsigned char & b)
{
    unsigned char temp;

    temp = a;
    a    = b;
    b    = temp;

    return;
}

//------------------------------------------------------------------------------
class GLTexture
{
	public:
		GLTexture(const char* file, GLenum target = GL_TEXTURE_2D ,GLint min_filter = GL_NEAREST, GLint mag_filter = GL_NEAREST);
		GLTexture(GLenum target = GL_TEXTURE_2D ,GLint min_filter = GL_NEAREST, GLint mag_filter = GL_NEAREST);
		~GLTexture();

		void operator = (const GLTexture& t);

		bool LoadTexture(const char* file);

		void free();
		void bind();

		GLuint& Texture();

		void* pixels;
		GLuint width, height, texture, min, mag, target,bpp;
};

#endif
