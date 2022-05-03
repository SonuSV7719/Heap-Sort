#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int n);

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int start = root;
    int leftIndex = 2 * root + 1; 
    int rightIndex = 2 * root + 2;

    // check whether left child of root is smaller or not 
    if (leftIndex < n && arr[leftIndex] > arr[largest])
        largest = leftIndex;
 
    // check whether right child of root is smaller or not
    if (rightIndex < n && arr[rightIndex] > arr[largest])
        largest = rightIndex;
    
    //base condition to stop recursion
    if (largest != root) {
        swap(arr[root], arr[largest]);
        cout << "Heapify process: ";
        display(arr, n);
        cout << endl;
        heapify(arr, n, largest);
    }


}

void heapSort(int arr[], int n)
{
    for (int i = n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    
    cout << "Enter how many elements you want to enter: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i<n; i++)
    {
        cout << "Enter Element: ";
        cin >> arr[i];
    }

    heapSort(arr, n);
    cout << "Sorted array is: ";
    display(arr, n);

    return 0;
}