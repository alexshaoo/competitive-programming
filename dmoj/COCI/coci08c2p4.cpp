#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2 * 1e9
#define LLINF 0x3f3f3f3f

ll calc(ll X, vector<ll> A, vector<ll> B) {
  ll tot = 0;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] > X) continue;
    tot++;
    tot += (X - A[i]) / B[i];
  }
  return tot;
}

ll calc_tempo(ll coco, vector<ll> A, vector<ll> B) {
  ll ini = 1, fim = INF, m, resp = INF;
  while (ini <= fim) {
    m = (ini + fim) / 2;
    ll cand = calc(m, A, B);
    if (cand >= coco) {
      resp = m;
      fim = m - 1;
    } else {
      ini = m + 1;
    }
  }
  return resp;
}

ll check(ll X, ll T, vector<ll> A, vector<ll> B, vector<ll> C, vector<ll> D) {
  ll coco = calc(X, A, B);
  ll tempo_abrir = calc_tempo(coco, C, D);
  return X + tempo_abrir >= T;
}

int main() {
  ll T;
  int N, M;
  vector<ll> A, B, C, D;

  cin >> T;
  cin >> N;
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    A.push_back(x);
    B.push_back(y);
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    ll x, y;
    cin >> x >> y;
    C.push_back(x);
    D.push_back(y);
  }

  ll ini = 1, fim = T, resp = T, m;
  while (ini <= fim) {
    m = (ini + fim) / 2;
    if (check(m, T, A, B, C, D)) {
      resp = m;
      fim = m - 1;
    } else {
      ini = m + 1;
    }
  }
  cout << resp << endl;
}