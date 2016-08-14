#include "Shader.h"
Shader::Shader(void)
{
	 mProgram = 0;
}

void Shader::setProgram( GLuint id )
{
	 mProgram = id;
}

void Shader::traslate( GLfloat x, GLfloat y, GLfloat z )
{

	 trans = glGetUniformLocation( mProgram, "Translate" );

	 for( int i = 0; i < 4; i++ )
		  for( int j = 0; j < 4; j++ )
		  move[i][j] = 0;

	 move[0][0] = 1;
	 move[0][3] = x;
	 move[1][1] = 1;
	 move[1][3] = y;
	 move[2][2] = 1;
	 move[2][3] = z;
	 move[3][3] = 1;

	 glUniformMatrix4fv( trans, 1, GL_FALSE, &move[0][0] );

}

void Shader::subTraslate( GLfloat x, GLfloat y, GLfloat z )
{
	 move[0][3] = x;
	 move[1][3] = y;
	 move[2][3] = z;

	 glUniformMatrix4fv( trans, 1, GL_FALSE, &move[0][0] );
}

void Shader::rotate( GLfloat x, GLfloat y, GLfloat z )
{
	 x *= RADIANS;
	 y *= RADIANS;
	 z *= RADIANS;

	 rotZ = glGetUniformLocation( mProgram, "RotateZ" );
	 rotX = glGetUniformLocation( mProgram, "RotateX" );
	 rotY = glGetUniformLocation( mProgram, "RotateY" );

	 for( int i = 0; i < 4; i++ )
		  for( int j = 0; j < 4; j++ )
		  {
		  roX[i][j] = 0; 
		  roY[i][j] = 0; 
		  roZ[i][j] = 0;
		  }

	 roX[0][0] = 1;
	 roX[1][1] = cos(x);
	 roX[1][2] = -sin(x);
	 roX[2][1] = sin(x);
	 roX[2][2] = cos(x);
	 roX[3][3] = 1;

	 roY[0][0] = cos(y);
	 roY[0][2] = sin(y);
	 roY[1][1] = 1;
	 roY[2][0] = -sin(y);
	 roY[2][2] = cos(y);
	 roY[3][3] = 1;

	 roZ[0][0] = cos(z);
	 roZ[0][1] = -sin(z);
	 roZ[1][0] = sin(z);
	 roZ[1][1] = cos(z);
	 roZ[2][2] = 1;
	 roZ[3][3] = 1;


	 glUniformMatrix4fv( rotX, 1, GL_FALSE, &roX[0][0] );
	 glUniformMatrix4fv( rotY, 1, GL_FALSE, &roY[0][0] );
	 glUniformMatrix4fv( rotZ, 1, GL_FALSE, &roZ[0][0] );

}

void Shader::subRotate( GLfloat x, GLfloat y, GLfloat z )
{
	 x *= RADIANS;
	 y *= RADIANS;
	 z *= RADIANS;

	 roX[1][1] = cos(x);
	 roX[1][2] = -sin(x);
	 roX[2][1] = sin(x);
	 roX[2][2] = cos(x);

	 roY[0][0] = cos(y);
	 roY[0][2] = sin(y);
	 roY[2][0] = -sin(y);
	 roY[2][2] = cos(y);

	 roZ[0][0] = cos(z);
	 roZ[0][1] = -sin(z);
	 roZ[1][0] = sin(z);
	 roZ[1][1] = cos(z);


	 glUniformMatrix4fv( rotX, 1, GL_FALSE, &roX[0][0] );
	 glUniformMatrix4fv( rotY, 1, GL_FALSE, &roY[0][0] );
	 glUniformMatrix4fv( rotZ, 1, GL_FALSE, &roZ[0][0] );
}

void Shader::scale( GLfloat x, GLfloat y, GLfloat z )
{

	 scal = glGetUniformLocation( mProgram, "Scalee" );

	 for( int i = 0; i < 4; i++ )
		  for( int j = 0; j < 4; j++ )
		  move2[i][j] = 0;

	 move2[0][0] = x;
	 move2[1][1] = y;
	 move2[2][2] = z;
	 move2[3][3] = 1;

	 glUniformMatrix4fv( scal, 1, GL_FALSE, &move2[0][0] );

}

void Shader::subScale( GLfloat x, GLfloat y, GLfloat z )
{
	 move2[0][0] = x;
	 move2[1][1] = y;
	 move2[2][2] = z;

	 glUniformMatrix4fv( scal, 1, GL_FALSE, &move2[0][0] );
}

void Shader::perspective( float fovy, float a, float n, float f )
{
	 perspe = glGetUniformLocation( mProgram, "PerspectiveProjection" );

	 float d = 1 / ( tan( fovy * RADIANS / 2 ) );

	 for( int i = 0; i < 4; i++ )
		  for( int j = 0; j < 4; j++ )
		  perspec[i][j] = 0;

	 perspec[0][0] = d/a;
	 perspec[1][1] = d;
	 perspec[2][2] = (n + f)/(n - f);
	 perspec[2][3] = ( 2 * n * f)/(n - f);
	 perspec[3][2] = -1;

	 glUniformMatrix4fv( perspe, 1, GL_FALSE, &perspec[0][0] );

}
