
class Solution {
 public:
  int countWinningSequences(string s) {
    vector<vector<vector<int>>> mem(
        s.length(), vector<vector<int>>(3, vector<int>(2 * s.length(), -1)));
    const long ans = count(s, 0, 0, 0, mem) + count(s, 0, 1, 0, mem) +
                     count(s, 0, 2, 0, mem);
    return (ans / 2) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of distinct sequences Bob can use to beat Alice for
  // s[i..n), where the previous character is `prev` (0: F, 1: W, 2: E) and the
  // number of points that Bob is having is `bob`.
  long count(const string& s, int i, int prev, int bob,
             vector<vector<vector<int>>>& mem) {
    if (i == s.length())
      return bob > 0 ? 1 : 0;
    // Map [-s.length(), s.length() - 1] to [0, 2 * s.length() - 1].
    int& res = mem[i][prev][bob + s.length()];
    if (res != -1)
      return res;

    long f = 0;  // If Bob summons a Fire Dragon at i.
    long w = 0;  // If Bob summons a Water Serpent at i.
    long e = 0;  // If Bob summons a Earth Golem at i.

    switch (s[i]) {
      case 'F':
        if (prev != 0)
          f = count(s, i + 1, 0, bob, mem) % kMod;
        if (prev != 1)
          w = count(s, i + 1, 1, bob + 1, mem) % kMod;
        if (prev != 2)
          e = count(s, i + 1, 2, bob - 1, mem) % kMod;
        break;
      case 'W':
        if (prev != 0)
          f = count(s, i + 1, 0, bob - 1, mem) % kMod;
        if (prev != 1)
          w = count(s, i + 1, 1, bob, mem) % kMod;
        if (prev != 2)
          e = count(s, i + 1, 2, bob + 1, mem) % kMod;
        break;
      case 'E':
        if (prev != 0)
          f = count(s, i + 1, 0, bob + 1, mem) % kMod;
        if (prev != 1)
          w = count(s, i + 1, 1, bob - 1, mem) % kMod;
        if (prev != 2)
          e = count(s, i + 1, 2, bob, mem) % kMod;
      default:
        break;
    }

    return res = f + w + e;
  }
};
