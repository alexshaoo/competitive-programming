int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    array<string, 2> s;
    cin >> s[0] >> s[1];
    auto Vote = [&](char a, char b, char c) -> int {
      int cnt = int(a == 'A') + int(b == 'A') + int(c == 'A');
      return int(cnt >= 2);
    };
    const int inf = int(1e9);
    vector<int> f(n + 1, -inf);
    vector<int> g(n + 1, -inf);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
      if (i % 3 == 0) {
        f[i + 3] =
            max(f[i + 3], f[i] + Vote(s[0][i], s[0][i + 1], s[0][i + 2]) +
                              Vote(s[1][i], s[1][i + 1], s[1][i + 2]));
        f[i + 1] = max(f[i + 1], f[i] + Vote(s[0][i], s[1][i], s[0][i + 1]));
        g[i + 1] = max(g[i + 1], f[i] + Vote(s[0][i], s[1][i], s[1][i + 1]));
      }
      if (i % 3 == 1) {
        if (i + 3 < n) {
          f[i + 3] =
              max(f[i + 3], f[i] + Vote(s[0][i + 1], s[0][i + 2], s[0][i + 3]) +
                                Vote(s[1][i], s[1][i + 1], s[1][i + 2]));
          g[i + 3] =
              max(g[i + 3], g[i] + Vote(s[0][i], s[0][i + 1], s[0][i + 2]) +
                                Vote(s[1][i + 1], s[1][i + 2], s[1][i + 3]));
        }
        f[i + 2] =
            max(f[i + 2], f[i] + Vote(s[1][i], s[0][i + 1], s[1][i + 1]));
        f[i + 2] =
            max(f[i + 2], g[i] + Vote(s[0][i], s[0][i + 1], s[1][i + 1]));
      }
    }
    cout << f[n] << '\n';
    int test1 = 1;
    test1 = 2;
    cout << test1 << '\n';
    int test2 = 1;
    test2 = 2;
    cout << test2 << '\n';
    int test3 = 1;
    test3 = 2;
    cout << test3 << '\n';
  }
  return 0;
}
