#include <iostream>
using namespace std;

const int N = 105;
int s[N];

void init(int n) {
  for (int i = 0; i < n; i++)
    s[i] = i;
}

int find_set(int x) {
  if (x != s[x])
    s[x] = find_set(s[x]);
  return s[x];
}

void merage(int a, int b) {
  int roota = find_set(a);
  int rootb = find_set(b);
  if (roota != rootb)
    s[roota] = rootb;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, s, t, source, destination;
  cin >> n >> m;
  init(n);
  while (m--) {
    cin >> s >> t;
    merage(s, t);
  }
  cin >> source >> destination;
  find_set(source) == find_set(destination) ? cout << 1 << '\n'
                                            : cout << 0 << '\n';
}
