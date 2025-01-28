#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t SIZE>
void print(const T (&array)[SIZE]) {
  for (size_t i = 0; i < SIZE; i++) cout << array[i] << " ";
  cout << '\n';
}

template <class ForwardIter>
void print(ForwardIter begin, ForwardIter end) {
  for (; begin != end; ++begin) cout << *begin << " ";
  cout << '\n';
}

#define ll long long

const int MXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int x[3] , y[3];
char c[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
  int s = x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
  c[0] = 'A' , c[1] = 'B' , c[2] = 'C';
  int l = sqrt(s);
  if (l*l != s) {
    cout << -1;
    return 0;
  }
  for (int i=0;i<3;i++) {
    if (x[i] > l || y[i] > l) {
      cout << -1;
      return 0;
    }
  }
  vector<int> v;
  for (int i=0;i<3;i++) {
    if (y[i] == l) swap(x[i],y[i]);
    if (x[i] == l) v.push_back(i);
  }
  if(v.size() == 3) {
    cout << l << '\n';
    for (int i=0;i<3;i++) {
      for (int j=0;j<y[i];j++) {
        for (int k=0;k<l;k++) cout << c[i] ;
        cout << '\n';
      }
    }
    return 0;
  }
  if (v.size() == 1) {
    int cur = y[v[0]];
    int le = l - cur;
    int co = 0;
    for (int i=0;i<3;i++) {
      if (i != v[0]) {
        if (y[i] == le) swap(x[i] , y[i]);
        if (x[i] == le) co++;
      }
    }
    if (co == 2) {
      cout << l << '\n';
      for (int i=0;i<cur;i++) {
        for (int j=0;j<l;j++) cout << c[v[0]];
        cout << '\n';
      }
      int o1 = (v[0] + 1) % 3;
      int o2 = (o1 + 1) % 3;
      for (int i=0;i<le;i++)
      {
        for (int j=0;j<y[o1];j++) cout << c[o1];
        for (int j=0;j<y[o2];j++) cout << c[o2];
        cout << '\n';
      }
      return 0;
    }
  }
  cout << -1 << '\n';
}