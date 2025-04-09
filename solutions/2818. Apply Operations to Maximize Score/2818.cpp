class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    const int n = nums.size();
    const int mx = ranges::max(nums);
    const vector<int> minPrimeFactors = sieveEratosthenes(mx + 1);
    const vector<int> primeScores = getPrimeScores(nums, minPrimeFactors);
    int ans = 1;
    // left[i] := the next index on the left (if any) s.t.
    // primeScores[left[i]] >= primeScores[i]
    vector<int> left(n, -1);
    // right[i] := the next index on the right (if any) s.t.
    // primeScores[right[i]] > primeScores[i]
    vector<int> right(n, n);
    stack<int> stack;

    // Find the next indices on the left where `primeScores` are greater or
    // equal.
    for (int i = n - 1; i >= 0; --i) {
      while (!stack.empty() && primeScores[stack.top()] <= primeScores[i])
        left[stack.top()] = i, stack.pop();
      stack.push(i);
    }

    stack = std::stack<int>();

    // Find the next indices on the right where `primeScores` are greater.
    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && primeScores[stack.top()] < primeScores[i])
        right[stack.top()] = i, stack.pop();
      stack.push(i);
    }

    vector<pair<int, int>> numAndIndexes;

    for (int i = 0; i < n; ++i)
      numAndIndexes.emplace_back(nums[i], i);

    ranges::sort(numAndIndexes,
                 [&](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first == b.first ? a.second < b.second : a.first > b.first;
    });

    for (const auto& [num, i] : numAndIndexes) {
      // nums[i] is the maximum value in the range [left[i] + 1, right[i] - 1]
      // So, there are (i - left[i]) * (right[i] - 1) ranges where nums[i] will
      // be chosen.
      const long rangeCount = static_cast<long>(i - left[i]) * (right[i] - i);
      const long actualCount = min(rangeCount, static_cast<long>(k));
      k -= actualCount;
      ans = static_cast<long>(ans) * modPow(num, actualCount) % kMod;
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }

  // Gets the minimum prime factor of i, where 1 < i <= n.
  vector<int> sieveEratosthenes(int n) {
    vector<int> minPrimeFactors(n + 1);
    iota(minPrimeFactors.begin() + 2, minPrimeFactors.end(), 2);
    for (int i = 2; i * i < n; ++i)
      if (minPrimeFactors[i] == i)  // `i` is prime.
        for (int j = i * i; j < n; j += i)
          minPrimeFactors[j] = min(minPrimeFactors[j], i);
    return minPrimeFactors;
  }

  vector<int> getPrimeScores(const vector<int>& nums,
                             const vector<int>& minPrimeFactors) {
    vector<int> primeScores;
    for (const int num : nums)
      primeScores.push_back(getPrimeScore(num, minPrimeFactors));
    return primeScores;
  }

  int getPrimeScore(int num, const vector<int>& minPrimeFactors) {
    unordered_set<int> primeFactors;
    while (num > 1) {
      const int divisor = minPrimeFactors[num];
      primeFactors.insert(divisor);
      while (num % divisor == 0)
        num /= divisor;
    }
    return primeFactors.size();
  }
};
