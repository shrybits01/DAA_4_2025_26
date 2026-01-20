#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void complexRec(int n)
{
    if (n <= 2)
        return;

    int p = n;
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++)
    {
        small[i] = i * i;
    }
    reverse(small.begin(), small.end());

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);
}

int main()
{
    int n;
    cin >> n;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 50; i++)
    {
        complexRec(n);
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time taken = " << duration.count() << " microseconds" << endl;

    return 0;
}

// Reccurance relation = 3T(n/2) + O(nlogn)
// Time complexity = O(n^(log3))
// depth of recusion tree = logn