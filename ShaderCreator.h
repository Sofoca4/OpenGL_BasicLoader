#ifndef SHADERCREATOR_H
#define SHADERCREATOR_H

#include <stdio.h>
#include "OpenGL.h"

class ShaderCreator
{

	public:

		 ShaderCreator();
	/*	 Define the program with the default names 
	 *	 FragmentShader.glfs
	 *	 VertexShader.glvs	*/

		 ~ShaderCreator();


		 bool createProgram( const char*, const char* );
	/*	 Initialize all the instance to execute a shader Program */


		 bool printProgramLog( const GLuint );
	/*	 Program: ID program		*/


		 bool printShaderLog( const GLuint );
	/*	 Shader: ID shader		*/


		 bool bind( void );
	/*	 Initialize the Program	*/


		 void unbind( void );
	/*	 Disable the Program		*/


		 GLuint mProgramID;


};


#endif
