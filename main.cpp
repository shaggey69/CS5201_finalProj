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

	//symMatrix<double> mySymMatrix(9);
	//MyArray<double> myArray(9);

	gauss_seidel<double> my_GS;
	deepDec<double> my_SD;

	MyArray<double> my_ans_GS;
	MyArray<double> my_ans_SD;

/*
	for (int i = 3 ; i < 300  ; i++)
	{
		int start_s=clock();
		int stop_s=clock();
		cout << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

		//my_ans_GS =  my_GS(myMesh.getMesh_mat(),  myMesh.getMesh_vect());
		//my_ans_SD =  my_SD(myMesh.getMesh_mat(),  myMesh.getMesh_vect());
	}
*/
		mesh<double> myMesh(8);

	my_ans_GS =  my_GS(myMesh.getMesh_mat(),  myMesh.getMesh_vect());
	cout << my_ans_GS << endl;
	my_ans_SD =  my_SD(myMesh.getMesh_mat(),  myMesh.getMesh_vect());
	cout << my_ans_SD << endl;




	return 0;
}

