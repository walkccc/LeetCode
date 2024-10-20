class Solution {
 public:
  int getSum(vector<int>& nums) {
    const int increasingSequenceSum = getSequenceSum(nums, 1);
    const int decreasingSequenceSum = getSequenceSum(nums, -1);
    const int arraySum = getArraySum(nums);
    return (increasingSequenceSum + decreasingSequenceSum -
            static_cast<long>(arraySum) + kMod) %
           kMod;
  }

 private:
  constexpr static int kMod = 1'000'000'007;

  // Returns the sum of all sequences in the array that are in consecutive
  // increasing order if `direction` is 1, or in consecutive decreasing order if
  // `direction` is -1.
  int getSequenceSum(const vector<int>& nums, int direction) {
    const int n = nums.size();
    long sequenceSum = 0;
    // {num: the number of subsequences ending in `num` so far}
    unordered_map<int, int> prefixCount;
    // {num: the number of subsequences starting from `num` so far}
    unordered_map<int, int> suffixCount;
    // prefixSubseqs[i] := the number of subsequences ending in nums[i]
    vector<int> prefixSubseqs(n);
    // suffixSubseqs[i] := the number of subsequences starting from nums[i]
    vector<int> suffixSubseqs(n);

    for (int i = 0; i < n; ++i) {
      const int prevNum = nums[i] - direction;
      const int subseqsCount =
          (prefixCount.contains(prevNum) ? prefixCount[prevNum] : 0) + 1;
      prefixSubseqs[i] = subseqsCount;
      prefixCount[nums[i]] += subseqsCount;
      prefixCount[nums[i]] %= kMod;
    }

    for (int i = n - 1; i >= 0; --i) {
      const int nextNum = nums[i] + direction;
      const int subseqsCount =
          (suffixCount.contains(nextNum) ? suffixCount[nextNum] : 0) + 1;
      suffixSubseqs[i] = subseqsCount;
      suffixCount[nums[i]] += subseqsCount;
      suffixCount[nums[i]] %= kMod;
    }

    for (int i = 0; i < n; ++i) {
      sequenceSum += static_cast<long>(nums[i]) * prefixSubseqs[i] % kMod *
                     suffixSubseqs[i];
      sequenceSum %= kMod;
    }

    return sequenceSum;
  }

  int getArraySum(const vector<int>& nums) {
    int arraySum = 0;
    for (const int num : nums)
      arraySum = (arraySum + num) % kMod;
    return arraySum;
  }
};
