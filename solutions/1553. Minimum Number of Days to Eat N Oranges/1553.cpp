class Solution {
 public:
  int minDays(int n) {
    if (n <= 1)
      return n;
    if (const auto it = mem.find(n); it != mem.cend())
      return it->second;
    return mem[n] = 1 + min(minDays(n / 3) + n % 3,  //
                            minDays(n / 2) + n % 2);
  }

 private:
  unordered_map<int, int> mem;
};
