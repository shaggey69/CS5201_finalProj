/*! \file
 *
 * the symmatric matrix class
 */
/*/*
# Symmetric Matrix class header
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 18.4.18
*/
#ifndef SYMMATRIC_H
#define SYMMATRIC_H
#include "matrix.h"
using namespace std;

template <typename T>
class symMatrix;

/*! Stream insertion operator for `symMatrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the m_matrix are printed to the ouptut stream. Each
 * array is printed on a new row.
 * \return the modified output stream.
 *
 */
template<class T>
ostream& operator<< (ostream& out ,  symMatrix<T> & mat);

/*! Stream insertion operator for `symMatrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post the m_matrix if filled with the input
 * \return the modified input stream.
 *
 */
template<class T>
istream& operator>> (istream& in ,  symMatrix<T> & mat);


/*! symMatrix calss
 * Reprents a NxN symMatrix Matrix
 * contains a:
 * m_size - represting the size of N
 * m_matrix - an myArray of myArrays represting the matrix
 */

template <class T>
class symMatrix : public Matrix<T>
{ 	
	private:
		MyArray<T> & operator[](const int i) const;
	public:

   /*! initialize constructor.
	  * A new symMatrix is craeted with dimensions
	  * equel to "size"
	  * \pre size must be bigger then 0! Will throw a
	  * a length Error otherwise
	  * \post a symMatrix is born!
	 	*/

		symMatrix(const int size);

		/*! = assignment
	  * turns the CO symMatrix into RHS symMatrix
	  * \pre none
	  * \post none
	  */

		symMatrix<T> & operator= (const symMatrix<T> & rhs) ;

		/*! + operator
	  * adds the sum of CO to rhs, retures a new Matrix 
	  * with the calculated values
	  * \pre size of CO must be equel to rhs, Will throw a
	  * a length Error otherwise. "+" binary operator
	  * must be defiend for T.
	  * \post a matrix is born!
	  */

		Matrix<T> operator+(const Matrix<T> & rhs) const;

		/*! - operator
	  * caclualtes the differnce of CO to rhs, retures a new Matrix 
	  * with the calculated values
	  * \pre size of CO must be equel to rhs, Will throw a
	  * a length Error otherwise. "-" binary operator
	  * must be defiend for T.
	  * \post a matrix is born!
	  */

		Matrix<T> operator-(const Matrix<T> & rhs) const;

		/*! Matrix multiplication
	  * caclualtes the multiplication of symMatrix and matrix, returens
	  * a new matrix with the calculated values
	  * \pre size of CO must be equel to rhs, Will throw a
	  * a length Error otherwise. "*" binary operator
	  * must be defiend for T.
	  * \post a matrix is born!
	  */

		Matrix<T> operator*(const Matrix<T> & rhs) const;

		/*! Matrix - Vector  multiplication
	  * caclualtes the multiplication of a symMatrix with an Array
	  * and returens a new Vector with the calculated values
	  * \pre size of CO must be equel to rhs array size! Will throw a
	  * a length Error otherwise. "*" binary operator
	  * must be defiend for T.
	  * \post a Vector is born!
	  */

		MyArray<T> operator*(const MyArray<T> & rhs) const;

		/*! Matrix Scaler multiplication
	  * caclualtes the multiplication of a symMatrix with a scaler
	  * and modifies the CO m_matrix with calculation
	  * \pre "*" binary operator must be defiend for T.
	  * \post none
	  */

		void scalerMulti(const T scaler);

	  /*! set size!
	  *
	  * \pre s must be postive
	  * \post none
	  */

		void setSize(const int size);

		/*! Matrix transpose calculator
	  * Creates a new matrix with is a trasposed version of the CO
	  * \pre none
	  * \post a Matrix is born
	  */

		symMatrix<T> transpose() ;

		/*! Set Matrix
	  * changes the value of m_matrix[i][j] and m_matrix[j][i] to x
	  * \pre 0 < i,j <size
	  * \post modified m_matrix
	  */

		void setMatrix(const int i ,const int j, const T x);

		/*! operaotr ()
	  * returns value of m_matrix[i][j]
	  * \pre 0 < i,j <size
	  * \post none
	  */
		T operator()(const int i,const int j ) const;
	
		/*! is diagonally dominant
	  * returns true if matrix is diagonally dominant. 
	  * false otherwise.
	  * \pre none
	  * \post none
	  */

		bool isDiagDom() const ;

		/*! Stream insertion operator for `symMatrix`.
		*
		* \pre Stream insertion operator is defined for `T`.
		* \post The contents of the m_matrix are printed to the ouptut stream. Each
		* array is printed on a new row.
		* \return the modified output stream.
		*
		*/

		friend ostream& operator<< <T> (ostream& out ,  symMatrix<T> & mat);
		
		/*! Stream insertion operator for `symMatrix`.
		*
		* \pre Stream insertion operator is defined for `T`.
		* \post the m_matrix if filled with the input
		* \return the modified input stream.
		*
		*/

		friend istream& operator>> <T> (istream& in ,  symMatrix<T> & mat);

};

#include "symMatrix.hpp"
#endif