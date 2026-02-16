#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
//priority_queue<int,deque<int>>q;
vector<int>v={11,10,9,8,7};
priority_queue<int,vector<int>,greater<>>q(greater<>(),v);

//priority_queue<int,vector<int>,greater<>>q(v.begin(),v.end()); //ok

//queue<int,vector<int>>n(v.begin(),v.end()); /queue will not accespt
/*q.push(10);
q.push(11);
q.push(12);
*/
cout<<q.top()<<endl;
    
    return 0;
}


