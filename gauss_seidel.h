/*! \file
 *
 * the Gauss-Seidel class.
 */

/*
# Gauss-Seidel header
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/
#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include "myArray.h"
#include "symMatrix.h"
#include <stdexcept>


/*!
 * the Gauss-Seidel calculation class
 *
*/
#include <cmath>

template <typename T>
class gauss_seidel
{
	public:

	/*! Operator () calculator!
  * \pre T must have the: "*" "/" "-" binary operators defiend for it
  * \post a New Array<T> is born
  *	\return steepest descent result for Ax=b. Where A is the Symetric Matrix and 
  * b is the Array
  */
	MyArray<T> operator()(const symMatrix<T> & arr, const MyArray<T> & vec) const;
	void helper (const symMatrix<T> & arr,const MyArray<T> & vec,
		const MyArray<T> & previous_Ans, MyArray<T> & ans) const;
};
#include "gauss_seidel.hpp"
#endif