class Solution {
 public:
  int subsequencesWithMiddleMode(vector<int>& nums) {
    const int n = nums.size();
    long ans = 0;
    unordered_map<int, int> left;
    unordered_map<int, int> right;

    for (int i = 0; i < 2; ++i)
      ++left[nums[i]];

    for (int i = 2; i < n; ++i)
      ++right[nums[i]];

    for (int i = 2; i < n - 2; ++i) {
      const int num = nums[i];
      if (--right[num] == 0)
        right.erase(num);

      const int leftCount = left[num];
      const int rightCount = right[num];
      const int leftOther = i - leftCount;
      const int rightOther = n - 1 - i - rightCount;

      // count[mode] = 5 -- [a a] a [a a]
      ans += nC2(leftCount) * nC2(rightCount);
      ans %= kMod;

      // count[mode] = 4 -- [a a] a [a ?]
      ans += nC2(leftCount) * rightCount % kMod * rightOther % kMod;
      ans %= kMod;

      // count[mode] = 4 -- [a ?] a [a a]
      ans += leftCount * leftOther % kMod * nC2(rightCount) % kMod;
      ans %= kMod;

      // count[mode] = 3 -- [a a] a [? ?]
      ans += nC2(leftCount) * nC2(rightOther) % kMod;
      ans %= kMod;

      // count[mode] = 3 -- [? ?] a [a a]
      ans += nC2(leftOther) * nC2(rightCount) % kMod;
      ans %= kMod;

      // count[mode] = 3 -- [a ?] a [a ?]
      ans +=
          leftCount * leftOther % kMod * rightCount % kMod * rightOther % kMod;
      ans %= kMod;

      // count[mode] = 2 -- [a ?] a [? ?]
      ans += leftCount * calc(num, leftOther, rightOther, left, right) % kMod;
      ans %= kMod;

      // count[mode] = 2 -- [? ?] a [a ?]
      ans += rightCount * calc(num, rightOther, leftOther, right, left) % kMod;
      ans %= kMod;

      ++left[num];
    }

    return ans % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns C(n, 2).
  long nC2(long n) {
    return n * (n - 1) / 2 % kMod;
  }

  // Returns the count of subsequences that have `a` as the middle number, where
  // invalid subsequences are excluded.
  long calc(int a, long other1, long other2,
            const unordered_map<int, int>& count1,
            const unordered_map<int, int>& count2) {
    // [a ?] a [? ?]
    long res = other1 * nC2(other2) % kMod;

    for (const auto& [b, b1] : count1) {
      if (b == a)
        continue;
      const long b2 = count2.contains(b) ? count2.at(b) : 0;
      // Exclude triples -- [a b] a [b b].
      res = (res - b1 * nC2(b2) % kMod + kMod) % kMod;
      // Exclude doubles -- [a b] a [b ?].
      res = (res - b1 * b2 % kMod * (other2 - b2) % kMod + kMod) % kMod;
    }

    for (const auto& [b, b2] : count2) {
      if (b == a)
        continue;
      const long b1 = count1.contains(b) ? count1.at(b) : 0;
      // Exclude doubles -- [a ?] a [b b].
      res = (res - (other1 - b1) * nC2(b2) % kMod + kMod) % kMod;
    }

    return res;
  }
};
