/*! \file
 *
 * the steepest descent  class
 */
/*
# steepest descent header
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/

#ifndef DEEPDEC_H
#define DEEPDEC_H
#include "myArray.h"
#include "symMatrix.h"
#include <stdexcept>


/*!
 * the steepest descent calculation class
 *
*/
#include <cmath>

template <typename T>
class deepDec
{
	public:

	/*! Operator () calculator!
  * \pre T must have the: "*" "/" "-" binary operators defiend for it
  * \post a New Array<T> is born
  *	\return steepest descent result for Ax=b. Where A is the Symetric Matrix and 
  * b is the Array
  */
	MyArray<T> operator()(const symMatrix<T> mat,const MyArray<T> arr) const;
};

#include "deepdec.hpp"
#endif