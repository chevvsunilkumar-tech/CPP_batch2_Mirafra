#include<iostream>
#include<memory>

using namespace std;

class A
{
public:
A()
{
cout<<"constrctir\n";
}
~A()
{

cout<<"destructor\n";
}


};

void display(shared_ptr<A>&p)
{
cout<<"in display function use count is "<<p.use_count()<<endl;

}

void caller_display(shared_ptr<A>p)
{
cout<<"in caller display ref count "<<p.use_count()<<endl;
display(p);
}

int main()
{
shared_ptr<A>p1=make_shared<A>();
cout<<"p1 ref count "<<p1.use_count()<<endl;
caller_display(p1);

cout <<"aftrereturning to main use count "<<p1.use_count()<<endl;
shared_ptr<A>p2=p1;
cout<<"p1 use count after assiging to p2"<<p1.use_count()<<endl;
shared_ptr<A>q=make_shared<A>();
shared_ptr<A>q1=q;

cout<<"q use count "<<q.use_count()<<endl;
q=p1;
cout<<"after q=p p use count "<<p1.use_count()<<"q1 use count "<<q1.use_count()<<endl;

/*

{
shared_ptr<A>p2=move(p1);
cout<<"use count sftre move "<<p2.use_count()<<endl;
//make_shared<A>(); call constrcutor and destructor saeme time;
shared_ptr<A>p3;// it will not call any construtor because we did not assign any memory 
}
cout<<"use count of p1 after block "<<p1.use_count()<<endl;

*/

}
