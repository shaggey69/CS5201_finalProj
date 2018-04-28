/*
# Symmatric Matrix function implments 
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 4.18.18
*/
template <typename T>   
symMatrix<T>::symMatrix(const int size)
{
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	this -> m_size =size;

	this -> m_matrix.setSize(size);

	for (int i = 0 ; i < size ; i++)
		this -> m_matrix[i].setSize(i+1);
}

template <typename T>   
symMatrix<T> & symMatrix<T>::operator= (const symMatrix<T> & rhs) 
{
	this -> clear();
	this -> m_size = rhs.getSize();
	for (int i = 0 ; i < rhs.getSize() ; i++)
		{
			this -> m_matrix[i][i] = rhs(i,i);
			for (int j = 0 ; j < i ; j++)
				this -> m_matrix[i][j] = rhs(i,j);
		}
	return *this;
}

template <typename T>   
Matrix<T> symMatrix<T>::operator+(const Matrix<T> & rhs) const
{

	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(rhs);

	for (int i = 0 ; i < rhs.getSize() ; i++)
		{
			retVal[i][i] = this -> m_matrix[i][i] + retVal[i][i] ;
			for (int j = 0 ; j < i ; j++)
			{
				retVal[i][j] = this -> m_matrix[i][j] + retVal[i][j];
				retVal[j][i] = this -> m_matrix[i][j] + retVal[j][i];
			}
		}
	
	return retVal;
}

template <typename T>   
Matrix<T> symMatrix<T>::operator-(const Matrix<T> & rhs) const
{

	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(rhs);

	for (int i = 0 ; i < rhs.getSize() ; i++)
		{
			retVal[i][i] = this -> m_matrix[i][i] - retVal[i][i] ;
			for (int j = 0 ; j < i ; j++)
			{
				retVal[i][j] = this -> m_matrix[i][j] - retVal[i][j];
				retVal[j][i] = this -> m_matrix[i][j] - retVal[j][i];
			}
		}	
	return retVal;
}

template <typename T>   
Matrix<T> symMatrix<T>::operator*(const Matrix<T> & rhs) const
{


	int theSize = this -> m_size;

	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 
	T sum = 0;

	Matrix<T> retVal(theSize);

	Matrix<T> temp(theSize);
	for (int i = 0 ; i < theSize ; i++)
		{
			temp.setMatrix(i,i,this->m_matrix[i][i]) ;
			for (int j = 0 ; j < i ; j++)
			{
				temp.setMatrix( i, j ,this->m_matrix[i][j]);
				temp.setMatrix( j, i , this->m_matrix[i][j]);
			}
		}

	for (int i = 0 ; i < (theSize) ; i++)
		for (int j = 0 ; j < (theSize) ; j++)
		{ 
			for (int k = 0 ; k < (theSize) ; k++)
				sum += temp(i,k)*rhs(k,j);
			retVal.setMatrix(i,j,sum) ;
			sum = 0;
		}			
	return retVal;
}

template <typename T>   
MyArray<T> symMatrix<T>::operator*(const MyArray<T> & rhs) const
{

	int theSize = this -> m_size;

	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix and vector must be of equel length"); 
	T sum = 0;
	MyArray<T> retVal(theSize);


	for (int i = 0 ; i < theSize ; i++)
		{ 
			for (int k = 0 ; k < theSize ; k++)
			{
				if (i >= k)
					sum += this->m_matrix[i][k]*rhs[k];
				else
					sum += this->m_matrix[k][i]*rhs[k];
			}
			retVal[i] = sum;
			sum = 0;
		}			
	return retVal;
}

template <typename T>   
void symMatrix<T>::scalerMulti(const T scaler)
{
	int theSize = this -> m_size;

	for (int i = 0 ; i < theSize ; i++)
	{
		this -> m_matrix[i][i] *= scaler;
		for (int j = 0 ; j < i ; j++)
			this -> m_matrix[i][j] *= scaler;
	}	
	return;
}


template <typename T>   
void symMatrix<T>::setSize(const int size)
{	
	this -> clear();
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	this -> m_size =size;

	this -> m_matrix.setSize(size);

	for (int i = 0 ; i < size ; i++)
		this -> m_matrix[i].setSize(i+1);
}


template <typename T>   
symMatrix<T> symMatrix<T>::transpose() 
{
	symMatrix<T> retVal(*this);

	return retVal;
}

template <typename T>   
T symMatrix<T>::operator()(const int i,const int j) const
{
	if (i >= j)
		return this -> m_matrix[i][j];
	return this -> m_matrix[j][i];

}

template <typename T>   
MyArray<T> & symMatrix<T>::operator[](const int i) const
{
	if (i < 0 || i >= this -> m_size) 
		throw std::length_error("i must be 0 < i <size"); 	
	return this -> m_matrix[i];
}

template <typename T>   
void symMatrix<T>::setMatrix(const int i ,const int j, const T x)
{
	if (i < 0 || i >=this-> m_size || j < 0 || j >=this-> m_size )
		throw std::length_error("i,j must be 0 < i,j < size"); 
	if (i >= j)
		this->m_matrix[i][j] = x;
	else
		this->m_matrix[j][i] = x;
	return;
}

template <typename T>   
bool symMatrix<T>::isDiagDom() const
{
	int theSize = this -> m_size;

	Matrix<T> temp(theSize);
	for (int i = 0 ; i < theSize ; i++)
	{
		temp.setMatrix(i,i,this->m_matrix[i][i]) ;
		for (int j = 0 ; j < i ; j++)
		{
			temp.setMatrix( i, j ,this->m_matrix[i][j]);
			temp.setMatrix( j, i , this->m_matrix[i][j]);
		}
	}

	T sum = 0;
	for (int i = 0 ; i < theSize ; i++)
	{
		for (int j = 0 ; j < theSize ; j++)
			if (i != j)
				sum += fabs(temp[i][j]);
		if (fabs(temp[i][i]) < sum )
			return false;
		sum = 0;
	}
	return true;
}

template <typename T>   
ostream& operator<<(ostream& out ,  symMatrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
	{
		for (int j = 0 ; j < mat.m_size ; j++)
		{
			if ( i==j )
				out << mat.m_matrix[i][i] << " ";
			else if (j > i)
				out << mat.m_matrix[j][i] << " ";
			else
				out << mat.m_matrix[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

template <typename T>   
istream& operator>>(istream& in ,  symMatrix<T> & mat)
{
	T trash = 0;
	for (int i = 0 ; i < mat.m_size ; i++)
	{
		for (int j = 0 ; j < i ; j++)
			in >> mat.m_matrix[i][j];
		in >> mat.m_matrix[i][i];
		for (int k = i+1; k < mat.m_size ; k++)
			in >> trash;
	}
	return in;
}
