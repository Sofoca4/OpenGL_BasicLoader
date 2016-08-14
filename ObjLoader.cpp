#include "ObjLoader.h"

ObjLoader::ObjLoader(){

}
ObjLoader::~ObjLoader(){

}


long int ObjLoader::fileToArray(const char* path, char** target )
{
     FILE* file;
     file = fopen(path, "r");

     if( file == NULL )
     {
	      perror("Error File");
	      return 0;
     }

     fseek( file, 0, SEEK_END);
     long int fileSize = ftell(file);
     if( fileSize < 10 )
     {
	      puts("The file must Constent atleast 10 characters");
	      return 0;
     }


     fileSize++;
     *target = (char*)malloc( fileSize * sizeof(char) );
     if ( *target == NULL )
     {
	      puts("Error to allocate memory");
	      return 0;
     }


     rewind(file);
     fread(*target, 1, fileSize, file);
     *(*target + fileSize - 2) = '\0';

     fclose(file);
     return fileSize;
}


bool ObjLoader::loadModel( const char* path, Vertices** vertice, unsigned short* verSize, unsigned int** index, unsigned short* indexSize )
{
     FILE* file;
     char character[100];
     *vertice = ( Vertices* ) malloc( 1000 * sizeof( Vertices ) );
     *index = ( unsigned int* ) malloc( 10000 * sizeof( unsigned int ));

     if ( *index == NULL || *vertice == NULL ) 
     {
	      puts("Error to allocate memory");
	      return false;
     }

     unsigned short i = 0;
     unsigned short o = 0;
     unsigned short n = 0;

     file = fopen(path, "r");
     if(file == NULL)
     {
	      perror("File");
	      return false;
     }

     while(1)
     {
	     if( feof(file) )
	     {
		      fclose(file);
		      break;
	     }

	     fscanf(file, "%s", character );
	     if( character[0] == (char)118 )
	     {
		     if( fscanf(file, "%f %f %f", &(*vertice + i)->x, &(*vertice + i)->y, &(*vertice + i)->z ) != 3 )
			      continue;

		     i++;
		     continue;
	     }
	     if( character[0] == (char)102 )
	     {
		     for ( n = 0; n < 3; n++ )
		     {
			      if( fscanf(file, "%d", (*index + o) ) != 1 )
					break;

			      *(*index + o) -= 1;
			      o++;
		     }
	     }

     }

     *verSize = i;
     *indexSize = o;
     *vertice = ( Vertices* ) realloc ( *vertice, ( i + 1 ) * sizeof( Vertices ) );
     *index = ( unsigned int* ) realloc ( *index, ( o + 1 ) * sizeof( int ));
     return true;

}

bool ObjLoader::loadModel( const char* path, Vertices** vertice, unsigned short* verSize, unsigned int** index, unsigned short* indexSize, const unsigned int srcWidth, const unsigned int srcHeight, const unsigned int width, const unsigned int height )
{
     FILE* file;
     char character[100];
     *vertice = ( Vertices* ) malloc( 1000 * sizeof( Vertices ) );
     *index = ( unsigned int* ) malloc( 10000 * sizeof( unsigned int ));

     if ( *index == NULL || *vertice == NULL ) 
     {
	      puts("Error to allocate memory");
	      return false;
     }

     unsigned short i = 0;
     unsigned short j = 0;
     unsigned short o = 0;
     unsigned short n = 0;

     file = fopen(path, "r");
     if(file == NULL)
     {
	      perror("File");
	      return false;
     }

     while(1)
     {
	     if( feof(file) )
	     {
		      fclose(file);
		      break;
	     }

	     fscanf(file, "%s", character );
	     if( character[0] == (char)118 )
	     {
		     if( fscanf(file, "%f %f %f", &(*vertice + i)->x, &(*vertice + i)->y, &(*vertice + i)->z ) != 3 )
			      continue;

		     i++;
		     continue;
	     }

	     for( j = 0; j < i; j++ )
	     {
		      vertice[j]->x = vertice[j]->x * srcWidth / width;
		      vertice[j]->y = vertice[j]->y * srcHeight / height;
	     }


	     if( character[0] == (char)102 )
	     {
		     for ( n = 0; n < 3; n++ )
		     {
			      if( fscanf(file, "%d", (*index + o) ) != 1 )
					break;

			      *(*index + o) -= 1;
			      o++;
		     }
	     }

     }

     *verSize = i;
     *indexSize = o;
     *vertice = ( Vertices* ) realloc ( *vertice, ( i + 1 ) * sizeof( Vertices ) );
     *index = ( unsigned int* ) realloc ( *index, ( o + 1 ) * sizeof( int ));
     return true;

}
