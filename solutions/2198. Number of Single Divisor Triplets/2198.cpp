class Solution {
 public:
  long long singleDivisorTriplet(vector<int>& nums) {
    constexpr int kMax = 100;
    long ans = 0;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int a = 1; a <= kMax; ++a)
      for (int b = a; count[a] > 0 && b <= kMax; ++b)
        for (int c = b; count[b] > 0 && c <= kMax; ++c) {
          const int sum = a + b + c;
          if (divisible(sum, a) + divisible(sum, b) + divisible(sum, c) != 1)
            continue;
          if (a == b)
            ans += static_cast<long>(count[a]) * (count[a] - 1) / 2 * count[c];
          else if (b == c)
            ans += static_cast<long>(count[b]) * (count[b] - 1) / 2 * count[a];
          else
            ans += static_cast<long>(count[a]) * count[b] * count[c];
        }

    return ans * 6;
  }

 private:
  int divisible(int sum, int num) {
    return sum % num == 0;
  }
};
