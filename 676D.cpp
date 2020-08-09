#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
int n, m, sofar = -1, x_i, y_i, x_f, y_f;
bitset<4> maze[4][1001][1001];
bool visited[4][1001][1001];
queue<pair<pair<int, int>, int> > q;
bitset<4> rotate(bitset<4> stat) {
  bool left = stat[3];
  stat <<= 1;
  stat[0] = left;
  return stat;
}
bitset<4> cvchr(char c) {  //ConVert CHaratoR
  switch (c) {
    case '+':
      return bitset<4>(string("1111"));
    case '-':
      return bitset<4>(string("1010"));
    case '|':
      return bitset<4>(string("0101"));
    case '^':
      return bitset<4>(string("0001"));
    case '>':
      return bitset<4>(string("0010"));
    case '<':
      return bitset<4>(string("1000"));
    case 'v':
      return bitset<4>(string("0100"));
    case 'L':
      return bitset<4>(string("0111"));
    case 'R':
      return bitset<4>(string("1101"));
    case 'U':
      return bitset<4>(string("1110"));
    case 'D':
      return bitset<4>(string("1011"));
    case '*':
      return bitset<4>(string("0000"));
  }
}
int cvno(int x) {  //ConVert NO.
  if (x < 0 || x >= 4) cout << "FUCK" << endl;
  return x == 3 ? 0 : x + 1;
}
int opd(int direc) {  //OPposite Direction
  direc += 2;
  return direc >= 4 ? direc - 4 : direc;
}
bool cw(int x, int y, int x_p, int y_p, int direc, int no) {  //Can Walk
  //assume x_p,y_p exists
  if (x < 0 || y < 0 || x >= n ||
      y >= m || no < 0 || no >= 4) return false;
  if (x == x_p && y == y_p) return true;
  if (maze[no][x_p][y_p][direc] && maze[no][x][y][opd(direc)]) return true;
  return false;
}
void chk() {  //CHecK
  int x, y, no;
  auto item = q.front();
  q.pop();
  x = item.first.first;
  y = item.first.second;
  no = item.second;
  if (x == x_f && y == y_f) {
    cout << sofar << '\n';
    cout.flush();
    _exit(0);
  }
  if (x < 0 || y < 0 || x >= n ||
      y >= m || no < 0 || no >= 4) return;
  if (visited[no][x][y]) return;
  if (cw(x, y - 1, x, y, 3, no)) q.push(MP(MP(x, y - 1), no));
  if (cw(x - 1, y, x, y, 0, no)) q.push(MP(MP(x - 1, y), no));
  if (cw(x, y + 1, x, y, 1, no)) q.push(MP(MP(x, y + 1), no));
  if (cw(x + 1, y, x, y, 2, no)) q.push(MP(MP(x + 1, y), no));
  q.push(MP(MP(x, y), cvno(no)));
  visited[no][x][y] = true;
}
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      maze[0][i][j] = cvchr(c);
    }
  for (int i = 1; i < 4; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++)
        maze[i][j][k] = rotate(maze[i - 1][j][k]);
  cin >> x_i >> y_i >> x_f >> y_f;
  x_i--;
  y_i--;
  x_f--;
  y_f--;
  q.push(MP(MP(x_i, y_i), 0));
  while (!q.empty()) {
    sofar++;
    int size_now = q.size();
    for (int i = 0; i < size_now; i++)
      chk();
  }
  puts("-1");
  return 0;
}