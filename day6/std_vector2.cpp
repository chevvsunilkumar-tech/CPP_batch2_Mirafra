// C++ program to illustrate the
// capacity function in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> g1;
	for (int i = 0; i<8; i++)
	{
	g1.push_back(i);
	}
	for (auto it  = g1.begin(); it != g1.end(); it++)
		cout << *it << " ";
    cout<<endl;
	cout << "Size : " << g1.size();
	cout << "\nCapacity : " << g1.capacity();
	cout << "\nMax_Size : " << g1.max_size()<<endl;

//resizes the vector size to 3
	 g1.resize(3);
	// prints the vector size after resize()
	cout << "\nSize : " << g1.size()<<endl;
    cout << "\nCapacity : " << g1.capacity()<<endl;
    for (auto it  = g1.begin(); it != g1.end(); it++)
		cout << *it << " ";

	// checks if the vector is empty or not
	if (g1.empty() == false)
		cout << "\nVector is not empty";
	else
		cout << "\nVector is empty";

	// Shrinks the vector
	g1.shrink_to_fit(); //resize capacity
	cout << "\nVector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
		cout << *it << " ";
	cout << "\nSize : " << g1.size()<<endl;
    cout << "\nCapacity : " << g1.capacity()<<endl;	

// // //g1.rbegin() and rend()
	g1.push_back(10);
	cout << "\nSize : " << g1.size()<<endl;
    cout << "\nCapacity : " << g1.capacity()<<endl;	
	g1.push_back(20);
	g1.push_back(30);
	g1.push_back(40);
 	cout << "\nSize : " << g1.size()<<endl;
	cout << "\nCapacity : " << g1.capacity()<<endl;
	for (auto it = g1.begin(); it != g1.end(); it++)
		cout << *it << " ";
	 cout<<endl;
	for (auto it = g1.rbegin(); it != g1.rend(); it++)
		cout << *it << " ";
	return 0;
}

