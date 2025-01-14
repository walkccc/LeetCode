class Solution {
 public:
  int mostFrequentPrime(vector<vector<int>>& mat) {
    constexpr int dirs[8][2] = {{1, 0},  {1, -1}, {0, -1}, {-1, -1},
                                {-1, 0}, {-1, 1}, {0, 1},  {1, 1}};
    const int m = mat.size();
    const int n = mat[0].size();
    int ans = -1;
    int maxFreq = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (const auto& [dx, dy] : dirs) {
          int num = 0;
          for (int x = i, y = j; 0 <= x && x < m && 0 <= y && y < n;
               x += dx, y += dy) {
            num = num * 10 + mat[x][y];
            if (num > 10 && isPrime(num))
              ++count[num];
          }
        }

    for (const auto& [prime, freq] : count)
      if (freq > maxFreq) {
        ans = prime;
        maxFreq = freq;
      } else if (freq == maxFreq) {
        ans = max(ans, prime);
      }

    return ans;
  }

 private:
  bool isPrime(int num) {
    for (int i = 2; i < sqrt(num) + 1; ++i)
      if (num % i == 0)
        return false;
    return true;
  }
};
