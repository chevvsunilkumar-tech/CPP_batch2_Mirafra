#include <iostream>
#include<stack>
using namespace std;
struct process
{
int p_id;
string p_name;
bool p_status;
process(int id,string name):p_status(false),p_name(name),p_id(id)
{


}

//friend function for insertion operator
friend ostream& operator <<(ostream &o,process &it)
{

cout<<"id :"<<it.p_id<<"\nname: "<<it.p_name;
it.p_status=true;
if(it.p_status)
{
cout<<"\nstatus: "<<"complted\n";

}
else
{

cout<<"\nstatus: "<<"incompleted\n";
}
return o;
}


};
using namespace std;

int main()
{
stack<process>s;

s.push({1,"whatsapp"}); 
s.push({2,"instragram"});
s.push({3,"telegram"});
s.push({4,"chatgpt"});
s.push({5,"google"});
s.push({6,"meta"});

while(!s.empty())
{
/*
auto it=s.top();
it.p_status=true;
cout<<"id :"<<it.p_id<<"\nname: "<<it.p_name;

if(it.p_status)
{
cout<<"\nstatus: "<<"complted\n";

}
else
{

cout<<"\nstatus: "<<"incompleted\n";

}*/
cout<<s.top()<<endl;
cout<<"_____________________________________\n";
s.pop();

}


    return 0;
}


