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
#include "tutorial_ii.h"

//------------------------------------------------------------------------------
Tutorial_II::Tutorial_II()
{
	SDL_WM_SetCaption("Tutorial 5 <Texture Mapping>",NULL);

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_car.LoadTexture("car.bmp");
	t_brick.LoadTexture("texture.bmp");
	t_me.LoadTexture("me-pred.bmp");
}

//------------------------------------------------------------------------------
Tutorial_II::~Tutorial_II()
{
	t_brick.free();
	t_me.free();
	t_car.free();
}

//------------------------------------------------------------------------------
void Tutorial_II::draw()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(-2.0f,-1.5f,-10.0f);

	glRotatef(angle_x,1.0f,0.0f,0.0f);
	glRotatef(angle_y,0.0f,1.0f,0.0f);
	glRotatef(angle_z,0.0f,0.0f,1.0f);

	t_me.bind();

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(2.0f,-1.5f,-10.0f);

	glRotatef(-1.0f*angle_x,1.0f,0.0f,0.0f);
	glRotatef(angle_y,0.0f,1.0f,0.0f);
	glRotatef(angle_z,0.0f,0.0f,1.0f);

	t_brick.bind();

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f,1.5f,-10.0f);

	glRotatef(-1.0f*angle_x,1.0f,0.0f,0.0f);
	glRotatef(-1.0f*angle_y,0.0f,1.0f,0.0f);
	glRotatef(-1.0f*angle_z,0.0f,0.0f,1.0f);

	t_car.bind();

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f( 1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f( 1.0f, -1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	angle_x += 0.4f;
	angle_y += 0.6f;
	angle_z += 0.8f;
}


