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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 3>> arr(n);  // start, end, index
  for (int i = 0; i < n; ++i) {
    cin >> arr[i][0] >> arr[i][1];
    arr[i][2] = i;
  }
  sort(all(arr));
  vector<int> rooms(n);
  priority_queue<pair<int, int>> end;
  set<int> av;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    while (!end.empty() && -end.top().first < arr[i][0]) {
      auto [_, room] = end.top();
      end.pop();
      av.insert(room);
    }
    if (av.empty()) {
      av.insert(ans + 1);
    }
    int room = *av.begin();
    end.push({-arr[i][1], room});
    rooms[arr[i][2]] = room;
    av.erase(room);
    ans = max(ans, (int)end.size());
  }
  cout << ans << '\n';
  for (int i = 0; i < n; ++i) {
    cout << rooms[i] << ' ';
  }
}
