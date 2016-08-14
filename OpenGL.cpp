#include "OpenGL.h"
Object object;
bool polygon = false;
Shader shad;

bool iniGL()
{

	 GLenum glewError = glewInit();
	 if( glewError != GLEW_OK )
	 {
		  printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
		  return false;
	 }

	 glMatrixMode( GL_PROJECTION );
	 glLoadIdentity();

	 glMatrixMode( GL_MODELVIEW );
	 glLoadIdentity();

	 glClearColor( 0.f, 0.f, 0.f, 1.f );

	 glEnable(GL_DEPTH_TEST);

	 GLenum error = glGetError();
	 if( error != GL_NO_ERROR )
	 {
		  puts("Error initializing OpenGL!");
		  return false;
	 }
	 return true;

}

bool loadMedia ()
{
	ShaderCreator programShader;
	ObjLoader loader;
	Vertices* vertex;
	unsigned int* index;
	char* vertexShader;
	char* fragmentShader;


	//Load Vertex Shader
	if( !loader.fileToArray( "VertexShader.glvs", &vertexShader ) )
		 return false;

	//Load Fragment Shader
	if( !loader.fileToArray( "FragmentShader.glfs", &fragmentShader ) )
		 return false;

	//Load Object or Shape
	if( !loader.loadModel( "untitled1.obj", &vertex, &object.vert, &index, &object.faces ) )
		 return false;

	//Create the Program
	if ( !programShader.createProgram( vertexShader, fragmentShader ) )
		 return false;

	object.pos.x = 0;
	object.pos.y = -0.35;
	object.pos.z = -2;
	object.rot.x = 0;
	object.rot.y = 0;
	object.rot.z = 0;


	//Generate Shape
	glGenBuffers( 1, &object.gVertexBuffer );
	glBindBuffer( GL_ARRAY_BUFFER, object.gVertexBuffer );
	glBufferData( GL_ARRAY_BUFFER, object.vert * sizeof( Vertices ), &vertex[0], GL_STATIC_DRAW );

	glGenBuffers( 1, &object.gIndexBuffer );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, object.gIndexBuffer );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, object.faces * sizeof( unsigned int ), &index[0], GL_STATIC_DRAW );

	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

	programShader.bind();


	//Declare Shader Attribs
	shad.setProgram( programShader.mProgramID ); 
	shad.traslate( object.pos.x, object.pos.y, object.pos.z );
	shad.rotate( object.rot.x, object.rot.y, object.rot.z );
	shad.perspective( 90, 1, 0.1, 100 );
	
	return true;
}

void render()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
       //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	glEnableClientState( GL_VERTEX_ARRAY );

		 glBindBuffer( GL_ARRAY_BUFFER, object.gVertexBuffer );
		 glVertexPointer(3, GL_FLOAT, 0, NULL );

		 glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, object.gIndexBuffer );
		 glDrawElements( GL_TRIANGLES, object.faces, GL_UNSIGNED_INT, NULL );
	
	glDisableClientState( GL_VERTEX_ARRAY );

	glutSwapBuffers();
}

void update()
{

}

void keyPressed( unsigned char key, int x, int y )
{

	 switch( key ){
	 case 'd':
		  object.pos.x += 0.25;
		break;
	 case 'a':
		  object.pos.x -= 0.25;
		break;
	 case 's':
		  object.pos.y -= 0.25;
		break;
	 case 'w':
		  object.pos.y += 0.25;
		break;
	 case 'k':
		  if( object.rot.x == 0 )
			   object.rot.x = 360;
		  object.rot.x -= 10; 
		break;
	 case 'j':
		  if( object.rot.x == 360 )
			   object.rot.x = 0;
		  object.rot.x += 10;
		break;
	 case 'h':
		  if( object.rot.y == 0 )
			   object.rot.y = 360;
		  object.rot.y -= 10;
		break;
	 case 'l':
		  if( object.rot.y == 360 )
			   object.rot.y = 0;
		  object.rot.y += 10;
		break;
	 case 'x':
		  if( object.rot.z == 360 )
			   object.rot.z = 0;
		  object.rot.z += 10;
		break;
	case 'c':
		  if( object.rot.z == 0 )
			   object.rot.z = 360;
		  object.rot.z -= 10;
		  break;
	case 'z':
		  object.pos.z += 0.10;
		  break;
	case 'q':
		  object.pos.z -= 0.10;
		  break;
	 }

	 shad.subTraslate( object.pos.x, object.pos.y, object.pos.z );
	 shad.subRotate( object.rot.x, object.rot.y, object.rot.z );

}
