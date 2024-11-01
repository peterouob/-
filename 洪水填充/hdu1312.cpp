#include <iostream>
using namespace std;
char mp[21][21];
int n = 0;
int m = 0;
int cnt;
void dfs(int row, int col)
{
    if (row < 0 || row >= n || col < 0 || col >= m || mp[row][col] == '#')
        return;
    cnt++;
    mp[row][col] = '#';
    dfs(row - 1, col);
    dfs(row + 1, col);
    dfs(row, col + 1);
    dfs(row, col - 1);
}

int main()
{
    while (cin >> m >> n)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mp[i][j] == '@')
                    dfs(i, j);
            }
        }
        cout << cnt << endl;
    }
}