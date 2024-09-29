#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int mod = 1e9 + 7, MM = 4e5+5;
int N, R, val, a[MM], rk[MM], num[MM][3];

int t(int x) {
	return x == val? 1: (x < val? 0 : 2);
}

int fun(int start) {
	vi tmp(rk, rk+2*N);
  rotate(tmp.begin(), tmp.begin()+1, tmp.begin()+2*start+1);
  for (int i=0; i<N; i++) {
    a[i] = tmp[2*i]; a[i+N] = tmp[2*i+1];
  }
	
  cl(num, 0);
  //weak guys, fixed position from 2 to N
  if (val >= N+2) {
   pi mx = {0, N-1}; int p = -1, cur = 0;
   for (int i=0; i<N; i++) {
     int pos = i ? i : N-1;
     if (a[i] == val || a[i+N]==val) p = i;
     if (a[i] >= N+2) num[pos][t(a[i])]++;
     if (a[i+N] >= N+2) num[pos][t(a[i+N])]++;
   }
   for (int i=N-1; i>=1; i--) {
     for (int j=0; j<3; j++) cur += num[i][j];
     cur--;
     mx = max(mx, {-cur, i-1});
   }
   vi stay(N), cnt(3, 0);
   for (int i=0; i<N-1; i++) {
     int pos = (mx.second - i + 2*(N-1) - 1) % (N-1) + 1;
     for (int j=0; j<3; j++) cnt[j] += num[pos][j];
     int pp = cnt[2]? 2 : (cnt[1]? 1: 0);
     cnt[pp]--;  stay[pos] = pp;
   }
   int fp = find(all(stay), 1) - stay.begin();
   return fp - (fp > p) * N;
  }
  //strong guys, keep rotating
  for (int i=0; i<N; i++) {
    num[i][t(a[i])]++; num[i][t(a[i+N])]++;
  }
  int rot = 0, win = num[0][0]? 0: (num[0][1]? 1: 2);
  num[0][win]--;  vi cnt(3, 0);
  for (int i=1; i<=3*N; i++) {
    for (int j=0; j<3; j++) {
      cnt[j] += num[(i-1)%N][j]; num[(i-1)%N][j] = 0;
    }
    int lose = cnt[0]? 0 : (cnt[1]? 1:2);
    cnt[lose]--;
    if (lose < win) swap(lose, win);
    num[(i-1)%N][lose]++;
    //the person
    if (lose == 1) {
      rot++;
      if (i > 2*N) {
        if (R < i) rot--;
        return (N-1 - (R+N-i)%N) - rot * N;
      }
    }
  }
}
int main() {
  scanf("%d %d", &N, &R);  R = R % N + 2*N;
  for (int i=0; i<2*N; i++) scanf("%d", &rk[i]);
  if (rk[0] == 1) { 
	  printf("%d\n", N); 
	  return 0; 
  }
  val = rk[0];
  int lo = 0, hi = N-1, pos = fun(N-1), ptr = N-1;
  pos = pos - (pos % N + N)%N;
  while (lo <= hi) {
    int mid = (lo + hi)/2;
    if (fun(mid) >= pos) {
    	ptr = mid; 
    	hi = mid-1;
    }
    else lo = mid + 1;
  }
  lo = 0; hi = N-1; 
  int best = fun(ptr), ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi)/2;
    if (fun(mid) <= best) { 
	    ans = mid; 
	    lo = mid + 1;
    }
    else hi = mid - 1;
  }
  printf("%d\n", ans+1);
}