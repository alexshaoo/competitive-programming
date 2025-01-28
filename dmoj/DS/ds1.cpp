#include <bits/stdc++.h>
using namespace std;

#define _DEBUG
template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename Head, typename... Tail>
string to_string(tuple<Head, Tail...> t);

string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(char c) { return string("'") + c + "'"; }
string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < (int) v.size(); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <int i, typename TupleType>
string tuple_values(TupleType t) {
  string s = "";
  if constexpr (i > 0) {
    s += tuple_values<i - 1, TupleType>(t);
    s += ", ";
  }
  s += to_string(get<i>(t));
  return s;
}
 
template <typename Head, typename... Tail>
string to_string(tuple<Head, Tail...> t) {
  using TupleType = tuple<Head, Tail...>;
  const string s = tuple_values<tuple_size<TupleType>::value - 1, TupleType>(t);
  return "(" + s + ")";
}

void debug_commas() {}

template <typename Head, typename... Tail>
void debug_commas(Head head, Tail... tail) {
  // comma before each element
  cerr << ", " << to_string(head);
  debug_commas(tail...);
}

template <typename Head, typename... Tail>
void debug_better(Head head, Tail... tail) {
  // no comma before first element
  cerr << "[" << to_string(head);
  debug_commas(tail...);
  cerr << "]" << endl;
}

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                      \
  do {                                  \
    cerr << "" << #__VA_ARGS__ << ": "; \
    debug_better(__VA_ARGS__);          \
  } while (0)
#else
#define debug(...) 42
#endif

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

// fucking andrew things
#define int ull
// IT FUCKING WORKED THIS KID IS FUCKED

const ull mod = 1e9+7;
const int MAXN = 1e5+5;

int N, M;
int arr[MAXN], bit[MAXN], freq[MAXN];

void update(int x, int v, int bit[]) {
	for (; x < MAXN; x += x&-x) bit[x] += v;
}

ull query(int l, int bit[]) {
	ull sum = 0;
	for (; l > 0; l -= l&-l) sum += bit[l];
	return sum;
}

ull query(int l, int r, int bit[]) {
	return query(r, bit) - query(l-1, bit);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	// bit init
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		debug(N, M, arr[i]);
		update(i, arr[i], bit);
		update(arr[i], 1, freq);
	}
	while (M--) {
		char op;
		cin >> op;
		// op c, change x-th element to y
		if (op == 'C') {
			int x, y;
			cin >> x >> y;
			// update freq of old by -1, new by 1
			update(arr[x], -1, freq);
			update(x, y-arr[x], bit);
			arr[x] = y;
			update(y, 1, freq);
		}
		// op s, sum of bit[x, y]
		if (op == 'S') {
			int x, y;
			cin >> x >> y;
			cout << query(x, y, bit) << '\n';
		}
		// op q, number of elements <= x
		if (op == 'Q') {
			int x;
			cin >> x;
			cout << query(x, freq) << '\n';
		}
	}
}
