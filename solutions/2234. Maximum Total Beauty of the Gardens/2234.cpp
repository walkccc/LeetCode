class Solution {
 public:
  long long maximumBeauty(vector<int>& flowers, long long newFlowers,
                          int target, int full, int partial) {
    const long long n = flowers.size();

    // If a garden is already complete, clamp it to the target.
    for (int& flower : flowers)
      flower = min(flower, target);
    ranges::sort(flowers);

    // All gardens are complete, so nothing we can do.
    if (flowers[0] == target)
      return n * full;

    // Having many new flowers maximizes the beauty value.
    if (newFlowers >=
        n * target - accumulate(flowers.begin(), flowers.end(), 0LL))
      return max(n * full,
                 (n - 1) * full + static_cast<long long>(target - 1) * partial);

    long long ans = 0;
    long long leftFlowers = newFlowers;
    // cost[i] := the cost to make flowers[0..i] the same
    vector<long long> cost(n);

    for (long long i = 1; i < n; ++i)
      // Plant (flowers[i] - flowers[i - 1]) flowers for flowers[0..i - 1].
      cost[i] = cost[i - 1] + i * (flowers[i] - flowers[i - 1]);

    int i = n - 1;  // flowers' index (flowers[i + 1..n) are complete)
    while (flowers[i] == target)
      --i;

    for (; leftFlowers >= 0; --i) {
      // To maximize the minimum number of incomplete flowers, we find the first
      // index j that we can't make flowers[0..j] equal to flowers[j], then we
      // know we can make flowers[0..j - 1] equal to flowers[j - 1]. In the
      // meantime, evenly increase each of them to seek a bigger minimum value.
      const int j = firstGreater(cost, i, leftFlowers);
      const long long minIncomplete =
          flowers[j - 1] + (leftFlowers - cost[j - 1]) / j;
      ans = max(ans, (n - 1 - i) * full + minIncomplete * partial);
      leftFlowers -= max(0, target - flowers[i]);
    }

    return ans;
  }

 private:
  int firstGreater(const vector<long long>& A, int maxIndex, long long target) {
    return upper_bound(A.begin(), A.begin() + maxIndex + 1, target) - A.begin();
  }
};
