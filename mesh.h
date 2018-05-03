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

template <typename T>
class mesh
{
	private:
		symMatrix<T> mesh_mat;
		MyArray<T> mesh_vect;

		template <T T_function(T)>
		T useFunc(const T value);
		void MakeTheMatrix(const int size);
		void MakeTheVect(const int size);

	public:
		mesh(const int size);
		symMatrix<T> & getMesh_mat() {return mesh_mat; };
		MyArray<T> & getMesh_vect() {return mesh_vect; };
};

#include "mesh.hpp"

#endif