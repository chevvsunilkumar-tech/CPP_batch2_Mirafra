#include <iostream>
int g=10;

void test(int n)
{
    if (n == 0)
    {
        std::cout << "Base case reached\n";
        return;
    }

    std::cout << "Entering test(" << n << ")\n";

    test(n - 1);
    g--;

    //std::cout << "Returning from test(" << n << ")\n";
}

int main()
{
    test(3);
    std::cout << "g :" << g << "\n";
    return 0;
}

