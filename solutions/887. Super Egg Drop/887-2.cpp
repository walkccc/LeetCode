class Solution {
 public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> mem(k + 1, vector<int>(n + 1, -1));
    return drop(k, n, mem);
  }

 private:
  // Returns the minimum number of moves to know f with k eggs and n floors.
  int drop(int k, int n, vector<vector<int>>& mem) {
    if (k == 0)  // no eggs -> done
      return 0;
    if (k == 1)  // one egg -> drop from 1-th floor to n-th floor
      return n;
    if (n == 0)  // no floor -> done
      return 0;
    if (n == 1)  // one floor -> drop from that floor
      return 1;
    if (mem[k][n] != -1)
      return mem[k][n];

    //   broken[i] := drop(k - 1, i - 1) is increasing with i
    // unbroken[i] := drop(k,     n - i) is decreasing with i
    // mem[k][n] := 1 + min(max(broken[i], unbroken[i])), 1 <= i <= n
    // Find the first index i s.t broken[i] >= unbroken[i], which minimizes
    // max(broken[i], unbroken[i]).

    int l = 1;
    int r = n + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      const int broken = drop(k - 1, m - 1, mem);
      const int unbroken = drop(k, n - m, mem);
      if (broken >= unbroken)
        r = m;
      else
        l = m + 1;
    }

    return mem[k][n] = 1 + drop(k - 1, l - 1, mem);
  }
};
