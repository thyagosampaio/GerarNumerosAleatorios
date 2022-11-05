#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int arr[15];
int sorts = 0;

int gerador()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 25);
    return dist(mt);
}

void setupArray()
{
    srand(time(0));
    cout << "Números gerados: " << endl;
    for (int i = 0; i < 15; i++)
    {
        arr[i] = gerador();
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int arr[], int n)
{
    cout << " Função BubbleSort Ativada. " << "\n";
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
    cout << " Função PrintArray ativada. " << "\n";
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void testArray(int arr[], int size)
{
    
    cout << "Função TestArray ativada." << "\n";
    int igual = 0;
    int need = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr[i] = gerador();
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
    setlocale(LC_ALL,"");
    setupArray();
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    sorts++;
    cout << "Números gerados apos o " << "primeiro " << "bubble sort: \n";
    printArray(arr, N);
    testArray(arr, N);
    cout << "\nFoi necessário " << sorts << " sorts" << endl;

    return 0;
}
