#include <iostream>
#include<set>

using namespace std;
struct cmp;
class task
{

string name;
int priority;
int id;
public:
task(string n,int p,int d ):name(n),priority(p),id(d)
{ 


}
friend struct cmp;
friend ostream& operator <<(ostream &out ,task &obj) 
{
cout<<"name :"<<obj.name<<" priority :"<<obj.priority<<" id :"<<obj.id<<endl;
return out;
}

};

struct cmp
{

bool operator ()(task obj1,task obj2) const
{
if(obj1.priority==obj2.priority)
{

return obj1.id<obj2.id;
}
return obj1.priority<obj2.priority;

}

};

int main()
{
  
set<task,cmp>s;
s.insert(task("sunil",1,2)) ;
s.insert(task("sunil",1,3)) ;
s.insert(task("sunil",5,4)) ;
s.insert(task("sunil",3,5)) ;

for(auto it:s)
cout<<it<<" ";
    return 0;
}


