#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

void printPaskalSpaces(int count)
{
    if (count > 1)
        printPaskalSpaces(count - 1);
    cout << "   ";
}

void printPaskalRow(int rowN, int currentValue)
{
    if (currentValue <= rowN)
    {
        cout << "     " << factorial(rowN) / (factorial(currentValue) * factorial(rowN - currentValue));
        printPaskalRow(rowN, currentValue + 1);
    }
}

void printPaskalTriangle(int countRows, int size)
{
    if (size < countRows) {
        printPaskalSpaces(countRows - size);
        printPaskalRow(size, 0);
        cout << endl;

        printPaskalTriangle(countRows, size + 1);
    }
}

int main()
{
    int size;

    cout << "Size > ";
    cin >> size;

    printPaskalTriangle(size, 0);

    return 0;
}