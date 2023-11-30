#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int row, column;
int mp[30][30];
int vis[30][30];
int org[30][30];
const int dirAny[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
const int d[2][2] = {{1, 0}, {0, 1}};

stack<pair<int, int>> run(int x, int y, stack<pair<int, int>> s)
{
    if (x == row && y == column)
    {
        s.push({x, y});
        vis[x][y] = 1;
        return s;
    }
    stack<pair<int, int>> emp, rtn;
    if (vis[x][y] || mp[x][y])
        return emp;
    s.push({x, y});
    vis[x][y] = 1;
    for (int i = 0; i < 2; i++)
    {
        int newX = x + d[i][0];
        int newY = y + d[i][1];
        rtn = run(newX, newY, s);
        if (!rtn.empty())
            return rtn;
    }
    return emp;
}

stack<pair<int, int>> runAny(int x, int y, stack<pair<int, int>> s)
{
    if (x == row && y == column)
    {
        s.push({x, y});
        vis[x][y] = 1;
        return s;
    }
    stack<pair<int, int>> emp, rtn;
    if (vis[x][y] || mp[x][y])
        return emp;
    s.push({x, y});
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int newX = x + dirAny[i][0];
        int newY = y + dirAny[i][1];
        rtn = runAny(newX, newY, s);
        if (!rtn.empty())
            return rtn;
    }
    return emp;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> row >> column;
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                org[i][j] = 1;
            }
        }
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= column; j++)
            {
                cin >> org[i][j];
            }
        }
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                mp[i][j] = 1;
                vis[i][j] = 0;
            }
        }
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= column; j++)
            {
                mp[i][j] = org[i][j];
            }
        }

        stack<pair<int, int>> s1, rtn1;
        // 先檢查是否能兩方向
        rtn1 = run(1, 1, s1);
        int rtnlength = rtn1.size();
        if (rtn1.size())
        {
            cout << "直角前進:" << rtn1.size() << "點" << endl;
            while (!rtn1.empty())
            {
                if (rtn1.size() == 1)
                    cout << "(" << rtn1.top().first << "," << rtn1.top().second << ")" << endl;
                else
                    cout << "(" << rtn1.top().first << "," << rtn1.top().second << ")<-";
                rtn1.pop();
            }
        }
        if (!rtnlength)
        {
            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    mp[i][j] = 1;
                    vis[i][j] = 0;
                }
            }
            for (int i = 0; i < 30; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    mp[i][j] = org[i][j];
                }
            }
            stack<pair<int, int>> s, rtn;
            rtn = runAny(1, 1, s);
            rtnlength = rtn.size();
            if (rtnlength)
            {
                cout << "任意方向:" << rtn.size() << "點" << endl;
                while (!rtn.empty())
                {
                    if (rtn.size() == 1)
                        cout << "(" << rtn.top().first << "," << rtn.top().second << ")" << endl;
                    else
                        cout << "(" << rtn.top().first << "," << rtn.top().second << ")<-";
                    rtn.pop();
                }
            }
        }
        if (!rtnlength)
            cout << "沒路" << endl;
        else
            cout << endl;
    }
}