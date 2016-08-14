#ifndef OPENGL_H
#define OPENGL_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <stdio.h>
#include "ObjLoader.h"
#include "ShaderCreator.h"
#include "../project/glew/include/GL/glew.h"
#include "Shader.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_FPS 60
#define PI 3.141592654/180

struct Posicion{

	 GLfloat x;
	 GLfloat y;
	 GLfloat z;

};

struct Rotation{

	 GLfloat x;
	 GLfloat y;
	 GLfloat z;

};

struct Object {

	 unsigned short vert;
	 unsigned short faces;
	 GLuint gVertexBuffer;
	 GLuint gIndexBuffer;
	 Posicion pos;
	 Rotation rot;

};

void runMainLoop(int);

void update();

void render();

bool iniGL();

bool loadMedia();

void keyPressed( unsigned char, int, int );

#endif
