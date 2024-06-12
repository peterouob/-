#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int eval()
{
    int x, y, z = 0;
    char token[MAX];
    memset(token, 0, MAX);
    scanf("%s", token);
    if (token[0] == 'f')
    {
        x = eval();
        return 2 * x - 3;
    }
    else if (token[0] == 'g')
    {
        x = eval();
        y = eval();
        return 2 * x + y - 7;
    }
    else if (token[0] == 'h')
    {
        x = eval();
        y = eval();
        z = eval();
        return 3 * x - 2 * y + z;
    }
    else
    {
        return atoi(token);
    }
}

int main()
{
    printf("%d", eval());
    return 0;
}