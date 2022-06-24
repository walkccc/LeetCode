class Solution {
 public:
  long long singleDivisorTriplet(vector<int>& nums) {
    long long ans = 0;
    vector<int> count(101);

    for (const int num : nums)
      ++count[num];

    for (int a = 1; a < 101; ++a)
      for (int b = a; count[a] && b < 101; ++b)
        for (int c = b; count[b] && c < 101; ++c) {
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
