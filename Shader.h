#ifndef SHADER_H
#define SHADER_H

#include <math.h>
#include <stdio.h>
#include "opengl.h"
#define RADIANS 3.141592654 / 180

class Shader 
{
	 public:

	 Shader(void);
	/*
	 * Specify the programID
	 */

	 void traslate ( GLfloat, GLfloat, GLfloat );
	 void subTraslate ( GLfloat, GLfloat, GLfloat );
      /*
	* x Axis
	* y Axis
	* z Axis	
	*/
	  
        void rotate ( GLfloat, GLfloat, GLfloat );
	 void subRotate( GLfloat, GLfloat, GLfloat );
      /*
	* The same parameters as before
	*/
	 
	 void scale( GLfloat, GLfloat, GLfloat );
	 void subScale( GLfloat, GLfloat, GLfloat );
	/*
	 * x, y and z axis
	 */

	 void perspective ( float, float, float, float );
      /*
	* fovy: Specify the angle view size in degrees
	* a: Aspect radio.
	* n: Near Value
	* f: Far value
	*/


	 void setProgram( GLuint );

	private:

	 GLuint mProgram;
	 GLint trans, rotX, rotY, rotZ, scal, perspe;
	 GLfloat move[4][4], move2[4][4]; 
	 GLfloat roX[4][4], roY[4][4], roZ[4][4];
	 GLfloat perspec[4][4];

};


#endif
