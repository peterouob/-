#include <cstring>
#include <stdio.h>
using namespace std;
const int INF = 0x3f3f3f;
const int N = 15 + 5;
int board[N][N], temp[N][N], vis[N][N], ans[N][N];
int n, m;
int min_step_ = INF;

int dict[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void reverse_(int u, int v) {
  vis[u][v] = 1;
  temp[u][v] ^= 1;
  for (int i = 0; i < 4; i++) {
    int x = u + dict[i][0];
    int y = v + dict[i][1];
    if (x >= 0 && x < n && y >= 0 && y < m) {
      temp[x][y] ^= 1;
    }
  }
}

bool check() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (temp[i][j] == 1)
        return false;
    }
  }
  return true;
}

void slove(int x) {
  memcpy(temp, board, sizeof(board));
  memset(vis, 0, sizeof(vis));

  int cnt = 0;
  for (int i = 0; i < m; i++) {
    // 狀態壓縮
    if ((x >> i) & 1) {
      cnt++;
      reverse_(0, i);
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (temp[i - 1][j] == 1) {
        cnt++;
        reverse_(i, j);
      }
    }
  }

  if (check() && cnt < min_step_) {
    min_step_ = cnt;
    memcpy(ans, vis, sizeof(vis));
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  // 枚舉
  for (int i = 0; i < (1 << m); i++) {
    slove(i);
  }

  if (min_step_ == INF) {
    printf("IMPOSSIBLE");
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        printf("%d ", ans[i][j]);
      }
      printf("%d\n", ans[i][m - 1]);
    }
  }
}
