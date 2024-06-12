#include <iostream>

using std::cout;

int perfect_num(int n)
{
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    if (sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    for (int i = 1; i < 1000; i++)
    {
        if (perfect_num((i)))
        {
            cout << i << "\n";
        }

    }
}
