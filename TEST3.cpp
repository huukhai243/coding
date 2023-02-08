#include <bits/stdc++.h>
#include <iostream>
#define MAX 10000
using namespace std;

int N;
int x[MAX];
int countss;
int solve()
{
    int ict = 100 * x[1] + 10 * x[2] + x[3];
    int k62 = 100 * x[7] + 62;
    int hust = 1000 * x[4] + 100 * x[5] + 10 * x[6] + x[3];

    int sum = ict - k62 + hust;
    return sum;
}
void solution()
{
    int sum = solve();
    if (sum == N)
        countss++;
}
bool check(int v, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (x[i] == v)
            return false;
    }
    return true;
}

void TRY(int k)
{

    for (int v = 1; v <= 9; v++)
    {
        if (check(v, k))
        {
            x[k] = v;

            if (k == 7)
                solution();
            else
                TRY(k + 1);
        }
    }
}

int main()
{

    cin >> N;
    TRY(1);
    cout << countss;
}