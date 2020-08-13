#include <iostream>
#include <cstring>
#include<algorithm>

using namespace std;

int dat[20][20];
int res[20][20];
int org[100][3];
int n, cnt = 0;
int k = 0;

//int max(int a, int b)
//{
//    if (a >= b)
//        return a;
//    else
//        return b;
//}

void gte()
{
    for (int i = 0;i < k;i++)
    {
        dat[org[i][0]][org[i][1]] = org[i][2];
    }
}

int dp()
{
    int i, j;
    for (i = 1;i <= n;i++)
        for ( j = 1;j <= n;j++)
        {
            res[i][j] = max(dat[i][j - 1], dat[i - 1][j]) + dat[i][j];
        }
    return res[n][n];
}

void bd()
{
    int i = n, j = n;
    while (i != 1 && j != 1)
    {
        if (res[i][j - 1] >= res[i - 1][j])
        {
            dat[i][j - 1] = 0;
            j = j - 1;
        }
        else
        {
            dat[i - 1][j] = 0;
            i = i - 1;
        }
    }
}

int main()
{
    int x, y, num;
    memset(dat, 0, sizeof(dat));
    memset(res, 0, sizeof(res));
    memset(org, 0, sizeof(org));
    cin >> n;
    do
    {
        cin >> x >> y >> num;
        org[k][0] = x;
        org[k][1] = y;
        org[k][2] = num;
        k++;
    }
    while (x != 0 && y != 0 && num != 0);
    gte();
    cnt += dp();
    bd();
    cnt += dp();
    cout << cnt;
}