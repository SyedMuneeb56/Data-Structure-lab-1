#include <iostream>
#include <string>
using namespace std;


template <typename T, int N>
void selectionSort(T(&A)[N])
{
    for (int i = 0; i < N - 1; i++)
    {
        int Swapping = i;

        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[Swapping])
            {
                Swapping = j;
            }
        }

        
        T temp = A[i];
        A[i] = A[Swapping];
        A[Swapping] = temp;
    }
}


template <typename T, int N>
void displayArray(T(&A)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    
    int intArray[5] = { 06, 57, 42, 70, 34 };
    
    cout << "Original integer array: ";
    displayArray(intArray);

    
    selectionSort(intArray);
    cout << "Sorted integer array: ";
    displayArray(intArray);

    
    string stringArray[4] = { "mango", "guava", "cherry", "apple" };
    cout << "\nOriginal string array: ";
    displayArray(stringArray);

   
    selectionSort(stringArray);
    cout << "Sorted string array: ";
    displayArray(stringArray);

    return 0;
}