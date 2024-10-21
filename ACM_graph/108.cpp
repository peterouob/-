#include <iostream>

using namespace std;

const int N = 1050;

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

void join(int a, int b) {
  int roota = find_set(a);
  int rootb = find_set(b);
  if (roota != rootb)
    s[roota] = rootb;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  init(n);
  while (n--) {
    int s, t;
    cin >> s >> t;
    if (find_set(s) == find_set(t)) {
      cout << s << " " << t;
      break;
    } else {
      join(s, t);
    }
  }
  return 0;
}
