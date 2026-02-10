#include <iostream>

struct SparseElement 
{
    int index;
    int value;
};

int main() 
{
    int arr[10] = {0, 0, 0, 5, 0, 0, 3, 0, 0, 0};

    int count = 0;
    SparseElement sparse[10];  // maximum possible size

    // Convert dense array to sparse format
    for (int i = 0; i < 10; ++i) 
    {
        if (arr[i] != 0) //finding non zero element
        {
            sparse[count].index = i; // i=index
            sparse[count].value = arr[i];
            count++;
        }
    }

    std::cout << "Sparse Representation:\n";
    for (int i = 0; i < count; ++i) 
    {
        std::cout << "Index: " << sparse[i].index
                  << ", Value: " << sparse[i].value << "\n";
    }

    return 0;
}

