#include <iostream>

using namespace std;

void array_print(int const* const array, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << array[i] << ' ';
    }
    cout << '\n';
}

void arr_print(int const* const arr, int m)
{
    for (int i = 0; i < m; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void quick_sort(int* array, int first, int second)
{
    int i = first;
    int j = second;
    int str = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < str)
            i++;
        while (array[j] > str)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > first)
        quick_sort(array, first, j);
    if (i < second)
        quick_sort(array, i, second);
}

void even_odd_Numbers(int* arr, int len)
{
    const int max = len;
    const int b = 10;
    int n;
    int numbers[b][max + 1];

    for (int i = 0; i < b; i++)
    {

        for (int j = 0; j<= max;j++)
        {
        numbers[i][j] = 0;
        }
    }

    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        for (int i = 0; i < max; i++)
        {
            if(arr[i] % 2 == 1)
               continue;
            int d = (arr[i] / digit) % b;
            int counters = numbers[d][max];
            numbers[d][counters] = arr[i];
            counters++;
            numbers[d][max]= counters;
        }
        int idx = 0;
        for (int i = 0; i < b; i++)
            {
                for (int j = 0; j < numbers[i][max]; idx++)
                {
                    if (arr[idx] % 2 == 0)
                    {
                        arr[idx] = numbers[i][j];
                        j++;
                    }
                }
                numbers[i][max] = 0;
            }
    }
}

int main(const int argc, const char **argv)
{
    int array[10] = {55, 85, 88, 39, 1, 495, 65, 378, 1, 2225};
    int n =  sizeof(array) / sizeof(array[0]);
    cout << "Array before quick sorting: " << endl;
    array_print(array, n);

    quick_sort(array,0,n);
    cout << "Array before after sorting: " << endl;
    array_print(array, n);

    const int SIZE = 12;
    int arr[SIZE] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
    cout << "Array before block sorting: " << endl;
    arr_print(arr, SIZE);

	cout << "Array after block sorting: " << endl;
	even_odd_Numbers(arr, SIZE);
    arr_print(arr, SIZE);
    return 0;
}
