#include<iostream>
using namespace std;

static int g;
int main()
{
	//const int a=10;
	int a=10;
	int b=20;
	int c=30;

	/*auto lam=[&,a,g](int data)
	  {
	//           a++;//error
	b++;
	g++;
	return data+a+b+c;
	};

	 */

	//auto lam =[&a]()  const    // error
	//auto lam =[&a]()  mutable   //  no no error
	// auto lam =[a]()   auto     // error

	auto lam =[a]()   mutable noexcept 
	{
		//      throw std::runtime_error("hi");// it wont affect program becuse we hav noexcept
      /*		try
		{
			if(a==10)
				throw "hi";
		//      throw std::runtime_error("hi");// it wont affect program becuse we hav noexcept
		}
		catch(...)
		{


		}
     */
             //   throw 10;	
	
	};
      try
{

	lam();
}
catch(...)
{
cout<<"my exception caught\n";
}
	int d=30;

	cout<<a<<endl;
	//   int res=lam(20);
	//  cout<<"res "<<res<<endl;
}
