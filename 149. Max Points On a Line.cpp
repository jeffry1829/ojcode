// #include <ext/pb_ds/assoc_container.hpp>
// typedef pair<int, int> PII;
// typedef long long ll;
// int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// struct P4D {
//   int x, y, a, b;
//   bool operator<(const P4D& other) const {
//     if (x == other.x) {
//       if (y == other.y) {
//         if (a == other.a) {
//           return b < other.b;
//         }
//         return a < other.a;
//       }
//       return y < other.y;
//     }
//     return x < other.x;
//   }
//   bool operator==(const P4D& other) const { return x == other.x and y == other.y and a == other.a and b == other.b; }
// };
// struct customhash {
//   size_t operator()(const P4D& p4d) const {
//     static const uint64_t RANDOM = std::chrono::high_resolution_clock::now().time_since_epoch().count();
//     return ((1ll * p4d.x) << 32) ^ ((1ll * p4d.y) << 32) ^ (1ll * p4d.a) ^ (1ll * p4d.b) ^ RANDOM;
//   }
// };
// class Solution {
//  public:
//   int maxPoints(vector<vector<int>>& points) {
//     // map<P4D, int> mp;
//     // map<P4D, int> havethistime;
//     __gnu_pbds::cc_hash_table<P4D, int, customhash> mp;
//     __gnu_pbds::cc_hash_table<P4D, int, customhash> havethistime;
//     int n = points.size();
//     for (int i = 1; i < n; i++) {
//       for (int j = i - 1; j >= 0; j--) {
//         PII delta = {points[i][0] - points[j][0], points[i][1] - points[j][1]};
//         if (delta.first < 0) {
//           delta.first = -delta.first;
//           delta.second = -delta.second;
//         }
//         int _gcd = gcd(abs(delta.first), abs(delta.second));
//         delta.first /= _gcd;
//         delta.second /= _gcd;
//         if (delta.first == 0) delta.second = 1;
//         if (delta.second == 0) delta.first = 1;
//         PII mostclosetoxzero;
//         if (delta.first == 0) {
//           mostclosetoxzero = {points[j][0], 0};
//         } else {
//           if (points[j][0] >= 0) {
//             int steps = points[j][0] / delta.first;
//             mostclosetoxzero = {points[j][0] - steps * delta.first, points[j][1] - steps * delta.second};
//           }

//           else {
//             int steps = -points[j][0] / delta.first;
//             if ((-points[j][0]) % delta.first) steps++;
//             mostclosetoxzero = {points[j][0] + steps * delta.first, points[j][1] + steps * delta.second};
//           }
//         }
//         P4D p4d = {delta.first, delta.second, mostclosetoxzero.first, mostclosetoxzero.second};
//         if (mp.find(p4d) != mp.end() and havethistime[p4d] != i) {
//           mp[p4d]++;
//         } else if (havethistime[p4d] != i) {
//           mp[p4d] = 2;
//         }
//         havethistime[p4d] = i;
//       }
//     }

//     int ans = 0;
//     for (auto& [p4d, cnt] : mp) {
//       ans = max(ans, cnt);
//     }
//     if (points.size() == 1) {
//       return 1;
//     }
//     return ans;
//   }
// };
typedef pair<int, int> PII;
typedef long long ll;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct P4D {
  int x, y, a, b;
  bool operator<(const P4D& other) const {
    if (x == other.x) {
      if (y == other.y) {
        if (a == other.a) {
          return b < other.b;
        }
        return a < other.a;
      }
      return y < other.y;
    }
    return x < other.x;
  }
  bool operator==(const P4D& other) const { return x == other.x and y == other.y and a == other.a and b == other.b; }
};
class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    map<P4D, int> mp;
    map<P4D, int> havethistime;
    int n = points.size();
    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        PII delta = {points[i][0] - points[j][0], points[i][1] - points[j][1]};
        if (delta.first < 0) {
          delta.first = -delta.first;
          delta.second = -delta.second;
        }
        int _gcd = gcd(abs(delta.first), abs(delta.second));
        delta.first /= _gcd;
        delta.second /= _gcd;
        if (delta.first == 0) delta.second = 1;
        if (delta.second == 0) delta.first = 1;
        PII mostclosetoxzero;
        if (delta.first == 0) {
          mostclosetoxzero = {points[j][0], 0};
        } else {
          if (points[j][0] >= 0) {
            int steps = points[j][0] / delta.first;
            mostclosetoxzero = {points[j][0] - steps * delta.first, points[j][1] - steps * delta.second};
          }

          else {
            int steps = -points[j][0] / delta.first;
            if ((-points[j][0]) % delta.first) steps++;
            mostclosetoxzero = {points[j][0] + steps * delta.first, points[j][1] + steps * delta.second};
          }
        }
        P4D p4d = {delta.first, delta.second, mostclosetoxzero.first, mostclosetoxzero.second};
        if (mp.find(p4d) != mp.end() and havethistime[p4d] != i) {
          mp[p4d]++;
        } else if (havethistime[p4d] != i) {
          mp[p4d] = 2;
        }
        havethistime[p4d] = i;
      }
    }

    int ans = 0;
    for (auto& [p4d, cnt] : mp) {
      ans = max(ans, cnt);
    }
    if (points.size() == 1) {
      return 1;
    }
    return ans;
  }
};