// Lab_06_2_rec

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateArrayWithRandomElements(int* a, int index, int numberOfElements, int Low, int High);
void PrintArray(int* a, int index, int numberOfElements);
double CalculateAverageOfEvenIndices(int* a, int index, int numberOfElements, int sum, int count);

int main()
{
    srand((unsigned)time(NULL));

    const int n = 24;
    int a[n];

    int Low = -17;
    int High = 53;
    CreateArrayWithRandomElements(a, 0, n, Low, High);
    cout << "Array with Random elements:" << endl;
    PrintArray(a, 0, n);
    cout << endl;

    double average = CalculateAverageOfEvenIndices(a, 0, n, 0, 0);
    if (average != -1)
        cout << "Average: " << average << endl;
    else
        cout << "No even elements found in the array." << endl;

    return 0;
}

void CreateArrayWithRandomElements(int* a, int index, int numberOfElements, int Low, int High)
{
    if (index >= numberOfElements)
        return;
    a[index] = Low + rand() % (High - Low + 1);
    CreateArrayWithRandomElements(a, index + 1, numberOfElements, Low, High);
}

void PrintArray(int* a, int index, int numberOfElements)
{
    if (index >= numberOfElements)
        return;
    cout << "a[" << setw(1) << index << "] = " << setw(1) << a[index] << "; ";
    if ((index + 1) % 9 == 0)
    {
        cout << endl;
    }
    PrintArray(a, index + 1, numberOfElements);
}

double CalculateAverageOfEvenIndices(int* a, int index, int numberOfElements, int sum, int count)
{
    if (index >= numberOfElements)
    {
        if (count > 0)
            return static_cast<double>(sum) / count;
        else
            return -1;
    }

    if (a[index] % 2 == 0)
    {
        sum += index;
        count++;
    }

    return CalculateAverageOfEvenIndices(a, index + 1, numberOfElements, sum, count);
}
