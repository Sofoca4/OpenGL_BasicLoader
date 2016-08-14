#include "ShaderCreator.h"

ShaderCreator::ShaderCreator()
{
	mProgramID = 0;
}


ShaderCreator::~ShaderCreator()
{

}


bool ShaderCreator::createProgram( const char* sVertexShader, const char* sFragmentShader )
{
	 mProgramID = glCreateProgram();

	 GLint programSuccess = GL_FALSE;

	 GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	 glShaderSource( vertexShader, 1, &sVertexShader, NULL );

	 glCompileShader(vertexShader);

	 GLint vShaderCompiled = GL_FALSE;
	 glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );
	 if ( vShaderCompiled != GL_TRUE )
	 {
		  printShaderLog(vertexShader);
		  return false;
	 }

	 glAttachShader(mProgramID, vertexShader);

	 GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	 glShaderSource(fragmentShader, 1, &sFragmentShader, NULL);

	 glCompileShader(fragmentShader);

	 GLint vFragmentCompiled = GL_FALSE;
	 glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &vFragmentCompiled );
	 if( vFragmentCompiled != GL_TRUE )
	 {
		  printShaderLog(fragmentShader);
		  return false;
	 }

	 glAttachShader(mProgramID, fragmentShader);

	 glLinkProgram(mProgramID);

	 glGetProgramiv(mProgramID, GL_LINK_STATUS, &programSuccess);
	 if( programSuccess != GL_TRUE )
	 {
		  printProgramLog(mProgramID);
		  return false;
	 }
	 return true;
}


bool ShaderCreator::printProgramLog(GLuint program)
{

	 if(glIsProgram(program))
	 {

		  int infoLogLength = 0;
		  int maxLength = infoLogLength;

		  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		  char* infoLog = new char[maxLength];

		  glGetProgramInfoLog(program, maxLength, &infoLogLength, infoLog);
		  if( infoLogLength > 0)
		  {
			   printf("Error: %s", infoLog);
			   return false;
		  }

		  delete[] infoLog;
	 
	 } else {
	 
		  printf("Name: %d is nos a program", mProgramID);
		  return false;
	 
	 }

	 return true;
}


bool ShaderCreator::printShaderLog(GLuint shader)
{

	 int infoLogLength = 0;
	 int maxLength = infoLogLength;

	 glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

	 char* infoLog = new char[maxLength];

	 glGetShaderInfoLog(shader, maxLength, &infoLogLength, infoLog);
	 if( infoLogLength > 0 )
	 {
	 	printf("Error: %s", infoLog);
	 }

	 delete[] infoLog;

}


bool ShaderCreator::bind()
{

	 glUseProgram(mProgramID);

	 GLenum error = glGetError();
	 if( error != GL_NO_ERROR )
	 {
		  printProgramLog(mProgramID);
		  return false;
	 }

	 return true;

}


void ShaderCreator::unbind()
{

	 glUseProgram(0);

}
