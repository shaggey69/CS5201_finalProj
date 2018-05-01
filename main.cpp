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

int main(int argc, char *argv[])
{
	int dimNum = 0;

	symMatrix<double> mySymMatrix(dimNum);
	MyArray<double> my_array;

	MyArray<double> my_ans_GS;
	MyArray<double> my_ans_SD;

	gauss_seidel<double> my_GS;
	deepDec<double> my_DS;

	ifstream in;

	if (argc < 2)
    cout << endl << "not enough inputs :(" << endl ;
  else  if (argc > 2)    
    cout << endl << "too many inputs :(" << endl ;
  else
  {
  	in.open(argv[1]);
		argc = 0;
		if (!in) 
    	cout << endl << "invailed file :("  << endl;
		else
		{
			in >> dimNum;

			mySymMatrix.setSize(dimNum);
			in >> mySymMatrix;

			my_array.setSize(dimNum);
			for (int i = 0 ; i < dimNum ; i++)
				in >> my_array[i];

			my_ans_GS = my_GS(mySymMatrix,my_array);
			cout << my_ans_GS << endl;

			my_ans_SD=my_DS(mySymMatrix,my_array);
			cout << my_ans_SD;


		}
	}



	return 0;
}

