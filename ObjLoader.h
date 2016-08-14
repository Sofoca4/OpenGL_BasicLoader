#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <stdio.h>
#include <stdlib.h>

struct Vertices {

		float x;
		float y;
		float z;

};

class ObjLoader 
{

	public:
		ObjLoader(); 
	/*	Empty Constructor		*/

		~ObjLoader();
	/*	Empty Destructor		*/


		bool loadModel( const char*, Vertices**, unsigned short*, unsigned int**, unsigned short* );
	/*	path: Specifies the name and directory of the file
	 *	Vertices: Specifies the target variable to store the vertices
	 *	verSize: Return as integer the number of vertices stored in Vertices
	 *	index: Specifies the target to store the index order to render Vertices
	 *	indexSize: Return as integer the number of index elements	*/

		bool loadModel( const char*, Vertices**, unsigned short*, unsigned int**, unsigned short*,
				  const unsigned int, const unsigned int, const unsigned int, const unsigned int );
	/*	path: Specifies the name and directory of the file
	 *	Vertices: Specifies the target variable to store the vertices
	 *	verSize: Return as integer the number of vertices stored in vertices
	 *	index: specifies the target to store the index order to render Vertices
	 *	indexSize: Return as integer the number of index elements
	 *	width: Specifies the actual width window size
	 *	height: Specifies the actual height window size		*/


		long int fileToArray( const char*, char** ); 
	/*	path: Specifies the name and directory of the file
	 *	size: Return the size of the file as unsigned int
	 *	target: Specifies the address of the variable to store the file
	 *	Return: This function return the number of charactesr in the file 
	 *	if any error happen will return 0		*/

};

#endif
