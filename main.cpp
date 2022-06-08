#include <algorithm>
#include <iostream>

#include "VecInt.hpp"

template <typename C>
int sz(const C &c)
{
    return static_cast<int>(c.size());
}

using namespace std;

int main()
{
    VecInt a = {34, 56, 4, 962, 121, 3, 1024};

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (int i = 0; i < sz(a); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    VecInt b(a);

    return 0;
}