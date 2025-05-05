class Solution {
 public:
  int countBalancedPermutations(string num) {
    vector<int> nums = getNums(num);
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1)
      return 0;

    ranges::sort(nums, greater<>());

    const int even = (nums.size() + 1) / 2;
    const int odd = nums.size() / 2;
    const int evenBalance = sum / 2;
    vector<vector<vector<long>>> mem(
        even + 1,
        vector<vector<long>>(odd + 1, vector<long>(evenBalance + 1, -1)));
    const long perm = getPerm(nums);
    return countBalancedPermutations(nums, even, odd, evenBalance, mem) *
           modInverse(perm) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of permutations where there are `even` even indices
  // left, `odd` odd indices left, and `evenBalance` is the target sum of the
  // remaining numbers to be placed in even indices.
  long countBalancedPermutations(const vector<int>& nums, int even, int odd,
                                 int evenBalance,
                                 vector<vector<vector<long>>>& mem) {
    if (evenBalance < 0)
      return 0;
    if (even == 0)
      return evenBalance == 0 ? factorial(odd) : 0;
    const int index = nums.size() - (even + odd);
    if (odd == 0) {
      long remainingSum = 0;
      for (int i = index; i < nums.size(); ++i)
        remainingSum += nums[i];
      return (remainingSum == evenBalance) ? factorial(even) : 0;
    }
    if (mem[even][odd][evenBalance] != -1)
      return mem[even][odd][evenBalance];
    const long placeEven =
        countBalancedPermutations(nums, even - 1, odd,
                                  evenBalance - nums[index], mem) *
        even % kMod;
    const long placeOdd =
        countBalancedPermutations(nums, even, odd - 1, evenBalance, mem) * odd %
        kMod;
    return mem[even][odd][evenBalance] = (placeEven + placeOdd) % kMod;
  }

  vector<int> getNums(const string& num) {
    vector<int> nums;
    for (const char c : num)
      nums.push_back(c - '0');
    return nums;
  }

  long getPerm(const vector<int>& nums) {
    long res = 1;
    vector<int> count(10);
    for (const int num : nums)
      ++count[num];
    for (const int freq : count)
      res = res * factorial(freq) % kMod;
    return res;
  }

  long factorial(int n) {
    long res = 1;
    for (int i = 2; i <= n; ++i)
      res = res * i % kMod;
    return res;
  }

  long modInverse(long a) {
    long m = kMod;
    long y = 0;
    long x = 1;
    while (a > 1) {
      const long q = a / m;
      long t = m;
      m = a % m;
      a = t;
      t = y;
      y = x - q * y;
      x = t;
    }
    return x < 0 ? x + kMod : x;
  }
};
