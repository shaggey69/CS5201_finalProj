/*! \file
 *
 * A Matrix class.
 */

/*
# Matrix class header
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 18.4.18
*/
#ifndef MATRIX_H
#define MATRIX_H
#include "myArray.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdexcept>

template <typename T>
class Matrix;

/*! Stream insertion operator for `Matrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the m_matrix are printed to the ouptut stream. Each
 * array is printed on a new row.
 * \return the modified output stream.
 *
 */

template<class T>
ostream& operator<< (ostream& out ,  Matrix<T> & mat);

/*! Stream insertion operator for `Matrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post the m_matrix if filled with the input
 * \return the modified input stream.
 *
 */

template<class T>
istream& operator>> (istream& in ,  Matrix<T> & mat);


/*! Matrix calss
 * Reprents a NxN Matrix
 * contains a:
 * m_size - represting the size of N
 * m_matrix - an myArray of myArrays represting the matrix
 */
template <class T>
class Matrix
{

	protected:

		/*! the matrix (Array of array's)
	  *
	  */
		MyArray <MyArray<T>> m_matrix;


		/*! size var
	  *
	  */

		int m_size;

		/*! clear
	  * dealoctes matrix 
	  * \pre none
	  * \post none
	  *
	  */


		void clear();


	public:



	   /*! defult constructor.
	  * A new Matrix is craeted with N equals 0. 
	  * \pre none
	  * \post a Matrix is born!
	  *
	  */

		Matrix (); 
  
	   /*! initialize constructor.
	  * A new Matrix is craeted with dimensions
	  * equel to "n"
	  * \pre size must be bigger then 0! Will throw a
	  * a length Error otherwise
	  * \post a Matrix is born!
	  *
	  */

		Matrix (const int n);

	  /*! copy constructor.
	  * A new Marix is craeted with size equel to RHS
	  * size.
	  * \pre none
	  * \post a Matrix is born!
	  *
	  */

		Matrix (const Matrix<T> & rhs);

	  /*! deconstructor.
	  *
	  * An Arnold Schwarzenegger Terminates the pointer
	  * to avoid Skynet taking over with their memorey Leacks.
	  * " Hasta La Vista , Pointer "
	  *
	  */

		~Matrix();

		/*! = assignment
	  * turns the CO Matrix into RHS matix
	  * \pre none
	  * \post none
	  */

		virtual Matrix<T>& operator= (const Matrix<T>& rhs) ;  

		/*! move constructor.
	  * A new Matrix is craeted with Size equel to RHS
	  * size
	  * \pre none
	  * \post a Matrix is born!
	  *
	  */

		Matrix(Matrix && rhs) : m_matrix(rhs.m_matrix), m_size(rhs.m_size)
		{ rhs.m_size = 0; }

		/*! + operator
	  * adds the sum of CO to rhs, retures a new Matrix 
	  * with the calculated values
	  * \pre size of CO must be equel to rhs, Will throw a
	  * a length Error otherwise. "+" binary operator
	  * must be defiend for T.
	  * \post a matrix is born!
	  */

		virtual Matrix<T> operator+(const Matrix<T> & rhs) const ;


		/*! - operator
	  * caclualtes the differnce of CO to rhs, retures a new Matrix 
	  * with the calculated values
	  * \pre size of CO must be equel to rhs, Will throw a
	  * a length Error otherwise. "-" binary operator
	  * must be defiend for T.
	  * \post a matrix is born!
	  */

		virtual Matrix<T> operator-(const Matrix<T> & rhs) const ;

		/*! Matrix multiplication
	  * caclualtes the multiplication of 2 matrixs and returens
	  * a new matrix with the calculated values
	  * \pre size of CO must be equel to rhs, Will throw a
	  * a length Error otherwise. "*" binary operator
	  * must be defiend for T.
	  * \post a matrix is born!
	  */

		virtual Matrix<T> operator*(const Matrix<T> & rhs) const ;

		/*! Matrix - Vector  multiplication
	  * caclualtes the multiplication of 2 of a Matrix with an Array
	  * and returens a new Vector with the calculated values
	  * \pre size of CO must be equel to rhs array size! Will throw a
	  * a length Error otherwise. "*" binary operator
	  * must be defiend for T.
	  * \post a Vector is born!
	  */

		virtual MyArray<T> operator*(const MyArray<T> & rhs) const;

		/*! object getter []
	  *
	  * \pre 0 < i < size, will throw a
	  * a length Error otherwise
	  * \post none
	  * \return Will return the MyArray at index i.
	  */

		 MyArray<T> & operator[](const int i) const ;

		/*! Matrix Scaler multiplication
	  * caclualtes the multiplication of a matrixs with a scaler
	  * and modifies the CO m_matrix with calculation
	  * \pre "*" binary operator must be defiend for T.
	  * \post none
	  */

		virtual void scalerMulti(const T scaler) ;

		/*! Row switcher
		* switches the array at index i with array at index j and
		* vice versa
		* \pre  0 < i,j < m_size, will throw a
	  * a length Error otherwise 
		* \post none
		*/

		virtual void switchRows (const int i, const int j) ; 

		/*! get matrix
		* returns m_matrix
		* \pre none
		* \post none
		*/



		MyArray <MyArray<T>> getMatrix() const {return m_matrix;}





	 /*! get size!
	  *
	  * \pre none
	  * \post none
	  * \return size of Martix
	  */

 
		int getSize() const {return m_size;};


	  /*! set size!
	  *
	  * \pre s must be postive
	  * \post none
	  */

		virtual void setSize(const int s);

  	/*! set matrix!
	  * changes value of m_matrix[i][j] to x
	  * \pre 0 < i,j < size.
	  * \post m_matrix modified
	  */


		virtual void setMatrix(const int i ,const int j, const T x);


	/*! Matrix transpose calculator
	  * Creates a new matrix with is a trasposed version of the CO
	  * \pre none
	  * \post a Matrix is born
	  */

		virtual Matrix<T> transpose() const ;
	
		/*! operaotr ()
		* returns value of m_matrix[i][j]
		* \pre 0 < i,j <size
		* \post none
		*/

		virtual T operator()(const int i,const int j ) const;
	
		/*! is diagonally dominant
	  * returns true if matrix is diagonally dominant. 
	  * false otherwise.
	  * \pre none
	  * \post none
	  */

		virtual bool isDiagDom() const ;

		/*! Stream insertion operator for `Matrix`.
		 *
		 * \pre Stream insertion operator is defined for `T`.
		 * \post The contents of the m_matrix are printed to the ouptut stream. Each
		 * array is printed on a new row.
		 * \return the modified output stream.
		 *
		 */

		  friend ostream& operator<< <T> (ostream& out ,  Matrix<T> & mat);

		/*! Stream insertion operator for `Matrix`.
		 *
		 * \pre Stream insertion operator is defined for `T`.
		 * \post the m_matrix if filled with the input
		 * \return the modified input stream.
		 *
		 */

		  friend istream& operator>> <T> (istream& in ,  Matrix<T> & mat);

};

/*! The compare Class.
 */
template <typename T>
class Compare
{
	/*! The () Operator
	*	returns true if lhs < rhs
	* \pre '<' operator defind for T! 
	* \post none
	*/
	public:
		bool operator() (const tuple <T,int> lhs, const tuple <T,int> rhs) const
		{
			return (get<0>(lhs)) > (get<0>(rhs));
		}
};

#include "matrix.hpp"

#endif