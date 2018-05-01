/*
# Gauss-Seidel implmention
# By: Ari Sherman & Alexn Shamore
# Class: CS5201 final project
# Date: 5.7.18
*/
// operator ()
#include <typeinfo>
template <typename T>
MyArray<T> gauss_seidel<T>::operator()(const symMatrix<T> & arr, const MyArray<T> & vec) const
{
	if (arr.getSize() != vec.getSize())
		throw std::length_error("Matrix and array must be of same size!");
	
	MyArray<T> previous_Ans(vec);
	MyArray<T> ans(arr.getSize());
	helper(arr,vec,previous_Ans,ans);
	//while (fabs(((ans*ans)-(previous_Ans*previous_Ans))) > 0.1)
	for (int i = 0 ; i < 20 ; i++)
	{
		previous_Ans = ans;
		helper(arr,vec,previous_Ans,ans);
		/*
		cout << "ans*ans is " << (ans*ans)<<endl ;
		cout << "previous_Ans*previous_Ans is " << (previous_Ans*previous_Ans) <<endl ;

		//T temp = 285.001 - previous_Ans*previous_Ans;

		cout << "while cond: " << (ans*ans)-(previous_Ans*previous_Ans) << endl ;
		*/
	}	
	return ans;
}

template <typename T>
void gauss_seidel<T>::helper (const symMatrix<T> & arr,const MyArray<T> & vec,
const MyArray<T> & previous_Ans, MyArray<T> & ans) const
{
	for (int i = 0 ; i < arr.getSize() ; i++)
	{
		T sum = 0;
		T temp = 0;
		for (int j = 0 ; j < arr.getSize() ; j++)
			if (i != j)
			{
				if (i > j)
					temp = previous_Ans[j];
				else
					temp = ans[j];
				sum += arr(i,j)*temp;
			}

		ans[i] = (vec[i] - sum)/arr(i,i);
	}
	return;
}

