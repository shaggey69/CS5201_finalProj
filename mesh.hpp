#include "functions.h"
/*
# Mesh class implmenation
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/
template <typename T>   
mesh<T>::mesh(const int size)
{
	MakeTheMatrix(size);
	MakeTheVect(size);
}


template <typename T>   
void mesh<T>::MakeTheMatrix(const int size)
{
	int tempCounter = 0 ;

	int sizeOfArray = ((size-1)*(size-1));
		
	mesh_mat.setSize(sizeOfArray);
	mesh_mat.zeroMe();	

	for (int i = 0 ; i < sizeOfArray ; i++)
	{
		mesh_mat.setMatrix(i,i,1);
		
		if ( i >= size-1)
		{
			mesh_mat.setMatrix(i,tempCounter, -0.25);
			tempCounter++;
		}
		if (i % (size-1))
		{
			mesh_mat.setMatrix(i,i-1, -0.25);
		}
	}
	return;
}

template <typename T>
void mesh<T>::MakeTheVect(const int size)
{
	mesh_vect.setSize((size-1)*(size-1));
	double stepSize = (1.0 / size);
	T sum = 0;
	double x, y;
	int count = 0;
	for(int i = 0; i < size-1; ++i)
	{
		y = (i + 1) * stepSize;
		for(int j = 0; j < size-1; ++j)
		{
			x = (j + 1) * stepSize;
			if(x - stepSize == 0)
			{
				sum += useFunc<function1>(y);
			}
			if(y - stepSize == 0)
			{
				sum += useFunc<function2>(x);
			}
			if(x - stepSize == 1)
			{
				sum += useFunc<function3>(y);
			}
			if(y - stepSize == 1)
			{
				sum += useFunc<function4>(x);
			}
			mesh_vect[count] = sum;
			sum = 0;
			count++;
		}
	}
	mesh_vect = mesh_vect * .25;

}

template <typename T>
template <T T_function(T)>
T mesh<T>::useFunc(const T value)
{
	return T_function(value);
}

