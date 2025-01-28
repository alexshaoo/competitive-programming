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
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> arr(n);
  vector<ll> check(n);
  vector<ll> vis(n);
  for (ll i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
    check[i] = i + arr[i].first - n;
  }
  sort(all(arr), [](pair<ll, ll> a, pair<ll, ll> b) {
    return a.first + a.second < b.first + b.second;
  });
  for (ll i = 0; i < n; ++i) {
    check[i] = arr[i].first + arr[i].second - n;
  }
  // print(all(check));
  deque<pair<ll, ll>> q;  // index, add
  for (auto it = lower_bound(all(check), 0); it != upper_bound(all(check), 0);
       ++it) {
    q.push_front({it - check.begin(), 0});
  }
  ll ans = 0;
  while (!q.empty()) {
    auto [ind, add] = q.front();
    // cout << arr[ind].first << ' ' << arr[ind].second << ' ' << add << '\n';
    q.pop_front();
    vis[ind] = true;
    add += arr[ind].second;
    auto l = lower_bound(all(check), add);
    // cout << add << ' ' << *l << '\n';
    if (*l != add) {
      ans = max(ans, add);
    }
    for (auto it = lower_bound(all(check), add);
         it != upper_bound(all(check), add); ++it) {
      // cout << "TRAVERSE MORE" << '\n';
      ll i = it - check.begin();
      if (!vis[i]) {
        q.push_back({i, add});
      }
    }
  }
  print(all(vis));
  cout << n + ans << '\n';
  // while (!q.empty()) {
  // cout << q.front().first << ' ' << q.front().second << ' ';
  // q.pop_front();
  // }
  // cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
