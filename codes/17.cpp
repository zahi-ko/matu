#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n;
    int first = 1;
    int second = 1;
    int res = 0;

    cin >> n;

    if (n<=2)
    {
        cout << 1;
    }
    else
    {
        for (; n>2; n--)
        {
            res = first + second;
            first = second;
            second = res;
        }
        cout << res;
    }
}
