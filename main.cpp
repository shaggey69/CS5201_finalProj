/*
# main 
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/

#include <iostream>
#include <fstream>
#include "symMatrix.h"
#include "myArray.h"
#include "mesh.h"
#include "gauss_seidel.h"
#include "deepdec.h"


using namespace std;

int main()
{

	//symMatrix<double> mySymMatrix(9);
	//MyArray<double> myArray(9);

	gauss_seidel<double> my_GS;
	deepDec<double> my_SD;

	MyArray<double> my_ans_GS;
	MyArray<double> my_ans_SD;

	mesh<double> myMesh(4);

	//mySymMatrix = myMesh.getMesh_mat();
	//myArray = myMesh.getMesh_vect();
	//cout<< mySymMatrix <<endl;
	//cout << myArray << endl;
	my_ans_GS =  my_GS(myMesh.getMesh_mat(),  myMesh.getMesh_vect());
	cout << my_ans_GS << endl;
	my_ans_SD =  my_SD(myMesh.getMesh_mat(),  myMesh.getMesh_vect());
	cout << my_ans_SD << endl;




	return 0;
}

