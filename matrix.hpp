/*
# Matrix function implments 
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 4.18.18
*/

template <typename T>   
Matrix<T>::Matrix()
{
	m_size = 0;
	m_matrix.setSize(0);
}

template <typename T>   
Matrix<T>::Matrix (const int n)
{
	if (n < 0)
		throw std::length_error("size must be greater then zero");
	m_size = n;
	m_matrix.setSize(n);
	for (int i = 0 ; i < m_size ; i++)
	{
		m_matrix[i].setSize(n);
	}
}

template <typename T>   
Matrix<T>::Matrix (const Matrix<T> & rhs)
{

	clear();
	m_size = rhs.m_size;
	m_matrix.setSize(m_size);	

	for (int i = 0 ; i < m_size ; i++)
 		m_matrix[i] = rhs.m_matrix[i];
}

template <typename T>   
Matrix<T>::~Matrix()
{
	clear();
}
 
template <typename T>   
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& rhs)
{

	clear();
	m_size = rhs.m_size;
	m_matrix.setSize(m_size);

	for (int i = 0 ; i < m_size ; i++)
 		m_matrix[i] = rhs.m_matrix[i];

 	return *this;
}

template <typename T>   
void Matrix<T>::clear()
{
	m_size = 0;
	return;
}

template <typename T>   
Matrix<T> Matrix<T>::operator+(const Matrix<T> & rhs) const
{
	if (rhs.m_size != m_size) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(m_size);
	for (int i = 0 ; i < m_size ; i++)
		for (int j = 0 ; j < m_size ; j++)
			retVal[i][j]= m_matrix[i][j]+rhs.m_matrix[i][j];
	return retVal;
}

template <typename T>   
Matrix<T> Matrix<T>::operator-(const Matrix<T> & rhs) const
{
	if (rhs.m_size != m_size) 
		throw std::length_error("matrix must be of equel length"); 
	Matrix<T> retVal(m_size);
	for (int i = 0 ; i < m_size ; i++)
		for (int j = 0 ; j < m_size ; j++)
			retVal[i][j]= m_matrix[i][j]-rhs.m_matrix[i][j];
	return retVal;
}

template <typename T>   
Matrix<T> Matrix<T>::operator*(const Matrix<T> & rhs) const
{
	if (rhs.m_size != m_size) 
		throw std::length_error("matrix must be of equel length"); 
	T sum = 0;
	Matrix<T> retVal(m_size);
	for (int i = 0 ; i < (m_size) ; i++)
		for (int j = 0 ; j < (m_size) ; j++)
		{ 
			for (int k = 0 ; k < (m_size) ; k++)
				sum += m_matrix[i][k]*rhs.m_matrix[k][j];
			retVal[i][j] = sum;
			sum = 0;
		}			
	return retVal;
}

template <typename T>   
MyArray<T>  Matrix<T>::operator*(const MyArray<T> & rhs) const
{
	if (rhs.getSize() != m_size) 
		throw std::length_error("matrix and vector must be of equel length"); 
	T sum = 0;
	MyArray<T> retVal(m_size);
	for (int i = 0 ; i < (m_size) ; i++)
		{ 
			for (int k = 0 ; k < (m_size) ; k++)
				sum += m_matrix[i][k]*rhs[k];
			retVal[i] = sum;
			sum = 0;
		}			
	return retVal;
}


template <typename T>   
void Matrix<T>::scalerMulti(const T scaler)
{
	for (int i = 0 ; i < m_size ; i++)
		for (int j = 0 ; j < m_size ; j++)
			m_matrix[i][j]= scaler*m_matrix[i][j];
	return;
}



template <typename T>   
MyArray<T> & Matrix<T>::operator[](const int i) const
{
	if (i < 0 || i >= m_size) 
		throw std::length_error("i must be 0 < i <size"); 	
	return m_matrix[i];
}



template <typename T>   
void Matrix<T>::switchRows(const int i, const int j)
{
	if (i < 0 || i >= m_size || j < 0 || j >= m_size )
		throw std::length_error("matrix must be of equel length"); 
	MyArray<T> temp;
	temp = m_matrix[i];
	m_matrix[i] = m_matrix [j];
	m_matrix[j] =temp;
	return;
}



template <typename T>   
void Matrix<T>::setSize(const int s)
{
	m_size = s;
	m_matrix.setSize(s);
	for (int i = 0 ; i < m_size ; i++)
	{
		m_matrix[i].setSize(s);
	}
	return;
}



template <typename T>   
void Matrix<T>::setMatrix(const int i ,const int j, const T x)
{
	m_matrix[i][j] = x;
	return;
}


template <typename T>   
Matrix<T> Matrix<T>::transpose() const
{
	Matrix<T> retVal(m_size);

	for (int i = 0 ; i < m_size ; i++)
		for (int j = 0 ; j < m_size ; j++)
		 	retVal.m_matrix[i][j] =	m_matrix[j][i];
	return retVal;
}

template <typename T>   
T Matrix<T>::operator()(const int i,const int j) const
{
	return m_matrix[i][j];
}

template <typename T>   
bool Matrix<T>::isDiagDom() const 
{
	T sum = 0;
	for (int i = 0 ; i < m_size ; i++)
	{
		for (int j = 0 ; j < m_size ; j++)
			if (i != j)
				sum += fabs(m_matrix[i][j]);
		if (fabs(m_matrix[i][i]) < sum )
			return false;
		sum = 0;
	}
	return true;
}



template <typename T>   
ostream& operator<<(ostream& out ,  Matrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
	{
		for (int j = 0 ; j < mat.m_size ; j++)
		{
			out << mat.m_matrix[i][j] << " ";
		}
		out << endl;
	}
	return out;
}


template <typename T>   
istream& operator>>(istream& in ,  Matrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
		for (int j = 0 ; j < mat.m_size ; j++)
			in >> mat.m_matrix[i][j];
	return in;
}
