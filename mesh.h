/*! \file
 *
 * the Mesh class.
 */

/*
# Mesh class header
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/
#ifndef MESH_H
#define MESH_H
#include <iostream>

using namespace std;

/*!
 * the Mesh calculation class
 *
*/

template <typename T>
class mesh
{
	private:

		/*! 
		* A symmetric matrix for Poisson’s quations 
		*/

		symMatrix<T> mesh_mat;

		/*! 
		* An array for Poisson’s quations 
		*/

		MyArray<T> mesh_vect;

		/*! use func
		* internal functinon templeted for Callbacks
		* \pre T must be defiend for whatever operators 
		* T_function uses
		* \post returns value after it's been modified
		* by T_function
		*/

		template <T T_function(T)>
		T useFunc(const T value);

		/*! MakeTheMatrix
		* internal functinon to create the Poisson’s Matrix
		* \pre none
		* \post "mesh_mat" is modfied
		*/

		void MakeTheMatrix(const int size);

		/*! MakeTheVect
		* internal functinon to create the Poisson’s Vector
		* \pre none
		* \post "mesh_vect" is modfied
		*/

		void MakeTheVect(const int size);

	public:

		/*! initilze constructor
		* functinos creates Poisson’s Vector and Matrix with given size 
		* \pre size must be greater then 0. Throws length error otherwise
		* \"mesh_vect" is modfied. "mesh_mat" is modfied.
		*/
		mesh(const int size);

		/*! getMesh_mat
		* retuerns mesh_mat
		* \pre none
		* \post none
		*/

		symMatrix<T> & getMesh_mat() {return mesh_mat; };

		/*! getMesh_vect
		* retuerns mesh_vect
		* \pre none
		* \post none
		*/

		MyArray<T> & getMesh_vect()  {return mesh_vect; };
};

#include "mesh.hpp"

#endif