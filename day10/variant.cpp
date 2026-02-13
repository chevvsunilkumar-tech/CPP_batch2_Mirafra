#include <iostream>
#include <variant>

int main() {
    std::variant<int, double,std::string> v;
  std:: cout<<sizeof(v);
}

