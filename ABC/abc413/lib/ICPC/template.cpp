// clang-format off
#include <bits/stdc++.h>
using namespace std;

namespace FUN_Morikubo {
template <class T> using vec = std::vector<T>;
template <class T> using vv = vec<vec<T>>;
template <class T> using vvv = vec<vec<vec<T>>>;
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;
using pi32 = pair<i32, i32>;
using pi64 = pair<i64, i64>;
using vi32 = vec<i32>;
using vi64 = vec<i64>;
using vpi32 = vec<pi32>;
using vpi64 = vec<pi64>;
using vvi32 = vec<vi32>;
using vvi64 = vec<vi64>;
using vvvi32 = vec<vvi32>;
using vvvi64 = vec<vvi64>;
using vs = vec<string>;
using vb = vec<bool>;
using vvb = vec<vb>;
using vvvb = vec<vvb>;
template <class T> using min_queue = priority_queue<T, vec<T>, greater<T>>;
template <class T> using max_queue = priority_queue<T>;
template <class S, class T> inline bool chmin(S& x, const T& y) { return (x > y) ? (x = y, true) : false; }
template <class S, class T> inline bool chmax(S& x, const T& y) { return (x < y) ? (x = y, true) : false; }
constexpr i64 TEN(i32 n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
constexpr i32 INF = 1 << 30;
constexpr i64 INFL = 1ll << 60;
constexpr i64 MOD93 = 998244353;
constexpr i64 MOD17 = 1000000007;
void YES(bool x) { cout << (x ? "YES" : "NO") << endl; }
void Yes(bool x) { cout << (x ? "Yes" : "No") << endl; }
void yes(bool x) { cout << (x ? "yes" : "no") << endl; }
constexpr i32 popcount(i32 x) { return __builtin_popcount((u32)x); }
constexpr i32 popcount(i64 x) { return __builtin_popcount((u64)x); }
template<class T> T randint(T l, T r) {
  assert(l <= r);
  random_device seed_gen;
  mt19937 engine(seed_gen());
  uniform_real_distribution<> rnd(l, r);
  return rnd(engine);
}
template<class T> struct binomial {
  i64 n; vec<T> fact, ifact;
  binomial(i64 n) : n(n), fact(n + 1), ifact(n + 1) {
    fact[0] = 1; for (i64 i = 1; i <= n; i++) { fact[i] = fact[i - 1] * i; }
    ifact[n] = 1 / fact[n]; for (i64 i = n - 1; i >= 0; i--) { ifact[i] = ifact[i + 1] * (i + 1); }
  }
  T operator()(i64 n, i64 k) { return (k < 0 || n < k) ? 0 : fact[n] * ifact[k] * ifact[n - k]; }
};
}  // namespace FUN_Morikubo
#define rep(i, N) for (i64 i = 0; i < (N); i++) 
#define rep1(i, N) for (i64 i = 1; i <= (N); i++)
#define rrep(i, N) for (i64 i = (N) - 1; i >= 0; i--) 
#define rrep1(i, N) for (i64 i = (N); i > 0; i--) 
#define FOR(i, a, b) for (i64 i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define UNIQUE(x) (x).erase(unique(all(x)), (x).end());
#define fs first
#define sc second
#define eb emplace_back
namespace std {
template <class T, class S> istream& operator>>(istream& is, pair<T, S>& x) { return is >> x.fs >> x.sc; }
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& x) { return os << x.fs << " " << x.sc; }
template <class T> istream& operator>>(istream& is, vector<T>& x) { for (auto& y : x) { is >> y; } return is; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& x) { for (size_t i = 0, size = x.size(); i < size; i++) { os << x[i] << (i == size - 1 ? "" : " "); } return os;}
}  // namespace std
// clang-format on
using namespace FUN_Morikubo;

struct Solver {
  void solve() {

  }
};

struct Solver;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  i64 T = 1;
//   cin >> T;
  while (T--) {
    Solver solver;
    solver.solve();
  }
}
