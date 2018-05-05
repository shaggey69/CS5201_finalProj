/*
# main 
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include "symMatrix.h"
#include "myArray.h"
#include "mesh.h"
#include "gauss_seidel.h"
#include "deepdec.h"


using namespace std;

int main()
{

	symMatrix<double> mySymMatrix(9);
	MyArray<double> myArray(9);


	deepDec<double> my_SD;
	gauss_seidel<double> my_GS;

	MyArray<double> my_ans_GS;
	MyArray<double> my_ans_SD;


	mesh<double> myMesh(4);

	myArray =  myMesh.getMesh_vect();

	mySymMatrix = myMesh.getMesh_mat();


	my_ans_GS =  my_GS(mySymMatrix,  myArray) ;

	my_ans_SD =  my_SD(mySymMatrix, myArray);

	cout << setprecision(8);

	cout << myArray << endl;
	cout << mySymMatrix << endl;
	cout << my_ans_GS << endl ;
	cout << my_ans_SD << endl ;

	return 0;
}

