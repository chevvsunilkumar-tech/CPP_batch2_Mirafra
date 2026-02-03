#include<iostream>
#include<vector>

using namespace std;


class gp
{
int a;

public:
gp(int i):a(i)
{
cout<<"constrcutor\n";
}
~gp()
{
cout<<"destrcutor\n";
}

gp(const gp&obj)
{
a=obj.a;
cout<<"copy constrcutir\n";
}

gp(gp &&obj) noexcept
{
a=obj.a;
obj.a=-1;
cout<<"move constrcutr\n";

}

};

int main()
{
vector<gp>v;
v.push_back(gp(1));
v.push_back(gp(2));//realloaction happpend so if noexcept is available call move otherwise copy


}

