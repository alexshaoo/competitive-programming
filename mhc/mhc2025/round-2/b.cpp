#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE> void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++)
    cout << array[i] << " ";
  cout << '\n';
}

template <class ForwardIter> void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin)
    cout << *begin << " ";
  cout << '\n';
}

#define ll long long
#define all(x) (x).begin(), (x).end()

const int MAXN = 1000000;
const int MOD = 1e9 + 7;
int freq[MAXN + 5];

void test_case() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> usedScores;
  int maxA = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int aa = a[i];
    if (freq[aa] == 0)
      usedScores.push_back(aa);
    freq[aa]++;
    if (aa > maxA)
      maxA = aa;
  }
  vector<int> b(m);
  ll totalUnits = 0;
  int typesCount = 0;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    totalUnits += b[i];
    if (b[i] > 0)
      typesCount++;
  }
  vector<ll> c; // groups
  for (int s = maxA; s >= 0; --s) {
    if (freq[s] > 0) {
      c.push_back(freq[s]);
    }
  }
  int K = c.size();
  for (int x : usedScores)
    freq[x] = 0;
  vector<ll> preCnt(K + 1, 0);
  vector<ll> preProd(K + 1, 0);
  for (int i = 1; i <= K; ++i) {
    preCnt[i] = preCnt[i - 1] + c[i - 1];
    preProd[i] = preProd[i - 1] + i * c[i - 1];
  }
  ll bestPlayers = 0;
  int maxL = min(K, typesCount);
  for (int L = 1; L <= maxL; ++L) {
    ll R_L = (L + 1) * preCnt[L] - preProd[L];
    if (R_L > totalUnits)
      break;
    bestPlayers = preCnt[L];
  }
  cout << bestPlayers << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    test_case();
  }
  return 0;
}
