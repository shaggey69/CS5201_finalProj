template <typename T>   
mesh<T>::mesh()
{
	mesh_mat.setSize(0);
	mesh_vec.setSize(0);
}


template <typename T>   
void mesh<T>::MakeTheMartix(const int size)
{
	int tempCounter = 0 ;

	int sizeOfArray = ((size-1)*(size-1));
		
	mesh_mat.setSize(sizeOfArray);
	mesh_mat.zeroMe();	

	for (int i = 0 ; i < sizeOfArray ; i++)
	{
		mesh_mat.setMatrix(i,i,1);
		
		if ( i >= size-1)
		{
			mesh_mat.setMatrix(i,tempCounter, -0.25);
			tempCounter++;
		}
		if (i % (size-1))
		{
			mesh_mat.setMatrix(i,i-1, -0.25);
		}
	}
	cout << mesh_mat;
	return;
}