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
#include "myglgame.h"
#include "tutorial_ii.h"

//------------------------------------------------------------------------------
MyGLGame::MyGLGame(int width,int height,int depth)
{
	surface = NULL;
	MyGLGame::width		= width;
	MyGLGame::height	= height;
	MyGLGame::depth		= depth;
}

//------------------------------------------------------------------------------
int MyGLGame::execute()
{
	SDL_Event event;
	Tutorial* tutorial;

	// Default SDL Startup ...
	if(SDL_Init(SDL_INIT_VIDEO) < 0) return -1;
	surface = SDL_SetVideoMode(width,height,depth,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_OPENGL|SDL_RESIZABLE);
	run 	= surface != NULL;

	// Default OpenGL
	resize(width,height);

	// Select a Tutorial ...
	tutorial = new Tutorial_II();

	// Eventloop
	while(run)
	{
		SDL_PollEvent(&event);

		switch(event.type)
		{
			case SDL_MOUSEMOTION:
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			case SDL_MOUSEBUTTONUP:
				break;
			case SDL_KEYDOWN:
				run = false;
				break;
			case SDL_QUIT:
				run = false;
				break;
			case SDL_VIDEORESIZE:
				break;
			default: break;
		}

		tutorial->draw();
		SDL_GL_SwapBuffers();
	};

	delete tutorial;
	SDL_Quit();
	return 0;
}

//------------------------------------------------------------------------------
void MyGLGame::resize(int width, int height)
{
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
