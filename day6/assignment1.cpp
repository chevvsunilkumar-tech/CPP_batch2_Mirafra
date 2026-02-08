#include <initializer_list>
#include<iostream>
#include<climits>
using std::cout;
using std::endl;
template<typename T>
class vector
{
	T* data;
	int size;
	int capacity;

	public:
	// default constructor
	// constructor
	vector(int n = 0, T value = T())
	{
		data = (n > 0) ? new T[n] : nullptr;
		size = n;
		capacity = n;

		for (int i = 0; i < n; i++)
		{
			data[i] = value;
		}
	}

	// initializer_list constructor
	vector(std::initializer_list<T> il)
	{
		size = il.size();
		capacity = il.size();
		data = capacity ? new T[capacity] : nullptr;

		int i = 0;
		for (auto& x : il)
			data[i++] = x;
	}

	// destructor
	~vector()
	{
		delete[] data;
	}

	// copy constructor
	vector(const vector& other)
	{
		size = other.size;
		capacity = other.capacity;
		data = capacity ? new T[capacity] : nullptr;

		for (int i = 0; i < size; i++)
			data[i] = other.data[i];
	}

	// copy assignment
	vector& operator=(const vector& other)
	{
		if (this != &other)
		{
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = capacity ? new T[capacity] : nullptr;

			for (int i = 0; i < size; i++)
				data[i] = other.data[i];
		}
		return *this;
	}

	// initializer_list assignment
	vector& operator=(std::initializer_list<T> il)
	{
		if (capacity < (int)il.size())
		{
			delete[] data;
			capacity = il.size();
			data = new T[capacity];
		}

		size = il.size();
		int i = 0;
		for (auto& x : il)
			data[i++] = x;

		return *this;
	}

	// move constructor
	vector(vector&& other)
	{
		data = other.data;
		size = other.size;
		capacity = other.capacity;

		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;
	}

	// move assignment
	vector& operator=(vector&& other)
	{
		if (this != &other)
		{
			delete[] data;
			data = other.data;
			size = other.size;
			capacity = other.capacity;

			other.data = nullptr;
			other.size = 0;
			other.capacity = 0;
		}
		return *this;
	}

	// size
	int vsize()
	{
		return size;
	}

	// capacity
	int vcapacity()
	{
		return capacity;
	}

	// empty
	bool empty()
	{
		return size == 0;
	}

	// max_size
	int max_size()
	{
		return INT_MAX / sizeof(T);
	}

	// operator[]
	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	// at
	T& at(int index)
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("out of range");
		return data[index];
	}

	const T& at(int index) const
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("out of range");
		return data[index];
	}

	// front / back
	T& front()
	{
		return data[0];
	}

	T& back()
	{
		return data[size - 1];
	}

	// begin / end
	T* begin()
	{
		return data;
	}

	T* end()
	{
		return data + size;
	}

	// rbegin / rend
	T* rbegin()
	{
		return data + size - 1;
	}

	T* rend()
	{
		return data - 1;
	}

	// assign({,,,,,})  
	void assign(std::initializer_list<T> list)
	{
		int n = list.size();

		if (capacity < n)
		{
			delete[] data;
			capacity = n;
			data = new T[capacity];
		}

		for (int i = 0; i < n; i++)
		{
			data[i] = *(list.begin() + i);
		}

		size = n;
	}


	// assign (count, value)
	void assign(int n, T value)
	{
		if (capacity < n)
		{
			delete[] data;
			capacity = n;
			data = new T[capacity];
		}

		for (int i = 0; i < n; i++)
			data[i] = value;

		size = n;
	}

	// assign (iterator range)
	void assign(T* first, T* last)
	{
		int n = last - first;
		if (capacity < n)
		{
			delete[] data;
			capacity = n;
			data = new T[capacity];
		}

		for (int i = 0; i < n; i++)
			data[i] = first[i];

		size = n;
	}

	// reserve
	void reserve(int n)
	{
		if (capacity < n)
		{
			T* ptr = new T[n];
			for (int i = 0; i < size; i++)
				ptr[i] = data[i];

			delete[] data;
			data = ptr;
			capacity = n;
		}
	}

	// resize
	void resize(int n)
	{
		if (n < size)
		{
			size = n;
			return;
		}

		if (n <= capacity)
		{
			for (int i = size; i < n; i++)
				data[i] = T();
			size = n;
			return;
		}

		T* ptr = new T[n];
		for (int i = 0; i < size; i++)
			ptr[i] = data[i];

		for (int i = size; i < n; i++)
			ptr[i] = T();

		delete[] data;
		data = ptr;
		capacity = n;
		size = n;
	}

	// shrink_to_fit
	void shrink_to_fit()
	{
		if (capacity > size)
		{
			T* ptr = new T[size];
			for (int i = 0; i < size; i++)
				ptr[i] = data[i];

			delete[] data;
			data = ptr;
			capacity = size;
		}
	}

	// clear
	void clear()
	{
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}

	// push_back
	void push_back(T d)
	{
		if (capacity == size)
			realloc();

		data[size++] = d;
	}

	// pop_back
	T pop_back()
	{
		if (size == 0)
			return T();
		return data[--size];
	}


	private:
	void realloc()
	{
		int n = (capacity == 0) ? 1 : capacity * 2;

		T* ptr = new T[n];
		for (int i = 0; i < size; i++)
			ptr[i] = data[i];

		delete[] data;
		data = ptr;
		capacity = n;
	}
};


int main()
{

	{
		cout<<"_____________________________________________________";
		cout<<"\n";
		vector<int>v{1,2,3,5};
		cout<<"elements of v\n";
		for(auto x:v)
		{
			cout<<x<<" ";
		}

		cout<<"\n";
		cout<<"2 nd element of v\n";
		cout<<v.at(2)<<endl;
		vector<int>v2;
		v2={11,22,33,44};
		cout<<"elements of v2\n";
		for(auto x:v2)
		{
			cout<<x<<" ";
		}
		cout<<endl;

		cout<<"____________________________________________________________";
	}

	cout<<endl;
	vector<int> v;

	cout << "empty: " << v.empty() << endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	cout << "vector elements: ";
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;

	cout << "front: " << v.front() << endl;
	cout << "back: " << v.back() << endl;

	v.resize(5);
	cout << "after resize of 5: ";
	for (auto x : v)
		cout << x << " ";
	cout << endl;

	v.assign({1, 2, 3, 4});
	cout << "after assign initializer_list: ";
	for (auto x : v)
		cout << x << " ";
	cout << endl;

	cout << "reverse iteration:";
	for (auto it = v.rbegin(); it != v.rend(); --it)
		cout << *it << " ";
	cout << endl;

	v.pop_back();
	cout << "after pop_back: ";
	for (auto x : v)
		cout << x << " ";
	cout << endl;

	cout << "size:" << v.vsize() << endl;
	cout << " capacity: " << v.vcapacity() << endl;

	v.clear();
	cout << "afterclear  empty: " << v.empty() << endl;


	return 0;
}

