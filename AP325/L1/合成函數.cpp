#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int eval()
{
    int x, y = 0;
    char token[MAX];
    scanf("%s", token);
    if (token[0] == 'f')
    {
        x = eval();
        return 2 * x - 1;
    }
    else if (token[0] == 'g')
    {
        x = eval();
        y = eval();
        return x + 2 * y - 3;
    }
    else
    {
        return atoi(token);
    }
}

int main()
{
    printf("%d",eval());
    return 0;
}