class Solution {
 public:
  int minSwaps(string s) {
    const int ones = count(begin(s), end(s), '1');
    const int zeros = s.length() - ones;
    if (abs(ones - zeros) > 1)
      return -1;
    if (ones > zeros)
      return countSwaps(s, '1');
    if (zeros > ones)
      return countSwaps(s, '0');
    return min(countSwaps(s, '1'), countSwaps(s, '0'));
  }

 private:
  int countSwaps(const string& s, char curr) {
    int swaps = 0;
    for (const char c : s) {
      if (c != curr)
        ++swaps;
      curr ^= 1;
    }
    return swaps / 2;
  }
};
