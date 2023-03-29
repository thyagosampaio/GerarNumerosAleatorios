#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int arr[15];
int sorts = 0;

void setupArray()
{
    srand(time(0));
    cout << "Números gerados: " << endl;
    for (int i = 0; i < 15; i++)
    {
        arr[i] = rand() % 26;
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void testArray(int arr[], int size)
{
    int igual = 0;
    int need = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr[i] = rand() % 26;
            igual++;
        }
        else if (igual > 0)
        {
            igual = 0;
            need++;
            break;
        }
    }

    bubbleSort(arr, size);
    sorts++;
    printArray(arr, size);
    if (need > 0)
    {
        testArray(arr, size);
    }


}

int main()
{
    setupArray();
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    sorts++;
    cout << "Números gerados após o " << "primeiro " << "bubble sort: \n";
    printArray(arr, N);
    testArray(arr, N);
    cout << "\nFoi necessario " << sorts << " sorts" << endl;

    return 0;
}
