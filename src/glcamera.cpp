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
#include "glcamera.h"
#include <GL/glu.h>

//------------------------------------------------------------------------------
GLCamera::GLCamera()
{}

//------------------------------------------------------------------------------
GLCamera::GLCamera( double x_eye,	  double y_eye,	   double z_eye,
		  			double x_center,  double y_center, double z_center,
		  			double x_up,	  double y_up,	   double z_up		 )
{
	LookAt(x_eye,y_eye,z_eye,x_center, y_center, z_center, x_up, y_up, z_up);
}

//------------------------------------------------------------------------------
void GLCamera::LookAt( double x_eye,	double y_eye,	 double z_eye,
				   	   double x_center,	double y_center, double z_center,
			       	   double x_up,		double y_up,	 double z_up		)
{
}

//------------------------------------------------------------------------------
void GLCamera::Look()
{
	gluLookAt(x_eye, y_eye, z_eye, x_center, y_center, z_center, x_up, y_up, z_up);
}

//------------------------------------------------------------------------------
void GLCamera::Move(DIRECTION d, double s)
{
	switch(d)
	{
		case UP:
			y_center += s;
			y_eye 	 += s;
			break;
		case DOWN:
			y_center -= s;
			y_eye 	 -= s;
			break;
		case RIGHT:
			x_center += s;
			x_eye 	 += s;
			break;
		case LEFT:
			x_center -= s;
			x_eye 	 -= s;
			break;
		case FORW:
			z_center += s;
			z_eye 	 += s;
			break;
		case BACKW:
			z_center -= s;
			z_eye 	 -= s;
			break;
	}
};

//------------------------------------------------------------------------------
