#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    // Create a map with string keys and integer values
    std::map<std::string, int,greater<>> studentScores;

    // Insert key-value pairs
     studentScores["Bob"] = 92;
    studentScores["Alice"] = 85;
   
    studentScores["Charlie"] = 78;
  

    // Alternatively, you can use insert method with std::pair
    studentScores.insert(std::make_pair("David", 90));
    studentScores.insert({"David", 90});//without pair

//    studentScores.insert(std::make_pair(9,"David"));// errro
    studentScores.emplace("Deen",58);
//    studentScores.emplace(make_pair("Deen",58));//error
    studentScores.emplace("Deen",80);//dublicates will be ignored
    studentScores["Charlie"] = 100;
    // Accessing elements
    std::cout << "Alice's score: " << studentScores["Alice"] << std::endl;

    // Iterate over the map (elements are sorted by key)
    std::cout << "\nStudent Scores:\n";
    for (const auto& entry : studentScores) {
        std::cout << entry.first << " : " << entry.second << std::endl;
    }

    // Checking if a key exists using find()
    if (studentScores.find("Deen") == studentScores.end())
    {
        std::cout << "\nData is not found in the map.\n";
    }
    else
    {
        std::cout << "\nData is found in the map.\n";
    }

    return 0;
}

