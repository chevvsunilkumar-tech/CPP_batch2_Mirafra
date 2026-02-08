#include<vector>
#include<string>
#include<iostream>
using namespace std;
struct Person {
std::string name;
int age;

Person(std::string n,int a) :name(n),age(a) {
        std::cout <<"Constructor\n";
    }

Person(const Person&) {
        std::cout <<"Copy constructor\n";
    }

Person(Person&&)noexcept {
        std::cout <<"Move constructor\n";
    }
};

int main() {
    std::vector<Person> v;
   Person obj("sunil",10);

    v.emplace_back(move(obj));
    //std::cout <<"push_back:\n";
  //  v.push_back(Person("dd",20));//why we wont get call move insted of constructor
//cout<<obj.name<<endl; 
    
//    std::cout <<"push_back:\n";
 //   v.push_back(Person("Alice",30)); 
  //  std::cout <<"\n1emplace_back:\n";
   // v.emplace_back("Bob",25);
/*
    std::cout <<"\n2emplace_back:\n";
     v.emplace_back("Sam",35);
      std::cout <<"\n3 emplace_back:\n";
     v.emplace_back("Joy",36);
     std::cout <<"4 emblace_back:\n";
      v.emplace_back("John",36); // cap =8 , ele =5
    //   v.emplace_back("Jovin",36); //constructor
    //  std::cout <<"push_back:\n";
     std::cout <<"push_back:\n";
     v.push_back(Person("Alvin",30)); //constru + mov
*/
}


