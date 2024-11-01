#include <cstdio>
#include <ios>
#include <queue>
#include <iostream>

typedef unsigned long long ull;
using namespace std;

ull num;

void slove()
{
  queue<ull> q;
  q.push(1);
  while (!q.empty())
  {
    ull n = q.front();
    q.pop();
    if(n % num == 0){
      cout << n << endl;
      return ;
    }
    q.push(n * 10);
    q.push(n * 10 + 1);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  while (cin >> num)
  {
    if (num == 0)
      break;
    slove();
  }
  return 0;
}
