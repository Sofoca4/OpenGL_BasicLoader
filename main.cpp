#include "OpenGL.h"


int main( int argc, char* args[] ){

	 glutInit(&argc, args);

	 glutInitContextVersion(2,1);

	 glutInitDisplayMode(GLUT_DOUBLE);
	 glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	 glutCreateWindow("Tester");

	 if(!iniGL())
	 {
		  puts("Unable to initializate graphics library\n");
		  return 1;
	 }

	 if(!loadMedia())
	 {
		  puts("Error to Load Media Files");
		  return 1;
	 }

	 glutKeyboardFunc(keyPressed);

	 glutDisplayFunc(render);

	 glutTimerFunc( 1000/SCREEN_FPS, runMainLoop, 0 );

	 glutMainLoop();

	 return 0;

}

void runMainLoop(int val)
{

	 update();
	 render();
	 glutTimerFunc(1000/SCREEN_FPS, runMainLoop, 0);

}
