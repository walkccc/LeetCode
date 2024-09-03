class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0)
      return true;

    const int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (sum < desiredTotal)
      return false;

    unordered_map<int, bool> mem;
    return canIWin(desiredTotal, 0, maxChoosableInteger, mem);
  }

 private:
  // Returns true if the first player can we, where `used` represents the used
  // numbers.
  bool canIWin(int total, int used, const int& maxChoosableInteger,
               unordered_map<int, bool>& mem) {
    if (total <= 0)
      return false;
    if (const auto it = mem.find(used); it != mem.cend())
      return it->second;

    for (int i = 1; i <= maxChoosableInteger; ++i) {
      if (used >> i & 1)  // Integer i is used.
        continue;
      if (!canIWin(total - i, used | 1 << i, maxChoosableInteger, mem))
        return true;
    }

    return mem[used] = false;
  }
};
