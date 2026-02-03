#include<iostream>

#include<memory>
using namespace std;

class sensor
{
 int data;
mutable int count;

public:

sensor(int d,int c):data(d),count(c)
{

}

~sensor()
{

}
void read() const
{

count++;

}
int get_count()const
{
return count;
}

int get_data() const
{
return data;
}
void write(int d) 
{

data=d;
cout<<"write function is executed\n";
}


};


int main()
{
unique_ptr<sensor>ptr=make_unique<sensor>(10,0);
ptr->read();
ptr->read();

cout<<"count :"<<ptr->get_count()<<endl;
ptr->write(20);
cout<<"data :"<<ptr->get_data()<<endl;
cout<<"const obj_______________"<<endl;
const sensor obj(10,3);
obj.read();
cout<<"const obj  count :"<<obj.get_count()<<endl;
//obj.write(100);

}
