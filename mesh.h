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
		MyArray<T> mesh_vec;
		T useFunc(const T x ,const T y);

	public:
		mesh();
		void MakeTheMartix(const int size);
		void MakeTheVec(const int size);
		symMatrix<T> & getMesh_mat() const {return mesh_mat; };
		MyArray<T> & getMesh_vec() const {return mesh_vec; };
};

#include "mesh.hpp"

#endif