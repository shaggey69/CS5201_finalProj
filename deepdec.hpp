/*
# steepest descent implmentaion
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/
// operator ()
template <typename T>
MyArray<T> deepDec<T>::operator()(const symMatrix<T> a,const MyArray<T> f) const
{
	if (!a.isDiagDom())
		throw std::length_error("Matrix must be Diagonal Dominate!");
	if (a.getSize() != f.getSize())
		throw std::length_error("Matrix and array must be of same size!");
	
	MyArray<T> resi(a.getSize());
	MyArray<T> x (f);
	
	MyArray<T> temp = a*x;
	MyArray<T> temp3;
	T temp1 ;
	T temp2 ;
	int number_of_iteratoins = 0;
	resi = f - (temp);

	while (resi*resi > 0.00000000001)
	{
		temp1 = resi*resi; 
		temp2 = a*resi*resi;
		T alfha =  temp1 / temp2;
		temp3 = resi*alfha;
		x = x + (temp3);
		temp = a*x;
		resi = f - (temp);
		number_of_iteratoins++;

	} 
	//cout << " " << number_of_iteratoins << endl;

	return x;
}

