#include <iostream>
using namespace std;


int sum(int arr[], int n)
{
    
    if (n == 0)
        return 0;

    
    return arr[n - 1] + sum(arr, n - 1);
}

int main()
{
    int arr[] = { 10, 20, 30, 40 };
    int n = 4;

    cout << "Sum = " << sum(arr, n);

    return 0;
}
