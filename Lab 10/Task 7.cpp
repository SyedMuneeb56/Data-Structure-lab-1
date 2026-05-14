#include <iostream>
using namespace std;


int findMax(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int max = findMax(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}


bool subsetSum(int arr[], int n, int target)
{
    if (target == 0)
        return true;

    if (n == 0)
        return false;

   
    return subsetSum(arr, n - 1, target) ||
        subsetSum(arr, n - 1, target - arr[n - 1]);
}


void removeElement(int arr[], int& n, int value, int i = 0)
{
    if (i == n)
        return;

    if (arr[i] == value)
    {
        for (int j = i; j < n - 1; j++)
            arr[j] = arr[j + 1];

        n--;
        return;
    }

    removeElement(arr, n, value, i + 1);
}


int magicNumber(int arr[], int n)
{
    if (n == 0)
        return -1;

    int largest = findMax(arr, n);

    removeElement(arr, n, largest);

    if (subsetSum(arr, n, largest))
        return largest;

    return magicNumber(arr, n);
}


int main()
{
    int arr[] = { 2, 3, 5, 8, 13 };
    int n = 5;

    cout << "Magic Number: " << magicNumber(arr, n);

    return 0;
}