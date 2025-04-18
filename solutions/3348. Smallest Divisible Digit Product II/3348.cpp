class Solution {
 public:
  string smallestNumber(string num, long long t) {
    const auto [primeCount, isDivisible] = getPrimeCount(t);
    if (!isDivisible)
      return "-1";

    const unordered_map<int, int> factorCount = getFactorCount(primeCount);
    if (sumValues(factorCount) > num.length())
      return consturct(factorCount);

    unordered_map<int, int> primeCountPrefix = getPrimeCount(num);
    int firstZeroIndex = num.find('0');
    if (firstZeroIndex == string::npos) {
      firstZeroIndex = num.length();
      if (isSubset(primeCount, primeCountPrefix))
        return num;
    }

    for (int i = num.length() - 1; i >= 0; --i) {
      const int d = num[i] - '0';
      // Remove the current digit's factors from primeCountPrefix.
      primeCountPrefix = substract(primeCountPrefix, kFactorCounts.at(d));
      const int spaceAfterThisDigit = num.length() - 1 - i;
      if (i > firstZeroIndex)
        continue;
      for (int biggerDigit = d + 1; biggerDigit < 10; ++biggerDigit) {
        // Compute the required factors after replacing with a larger digit.
        const unordered_map<int, int> factorsAfterReplacement =
            getFactorCount(substract(substract(primeCount, primeCountPrefix),
                                     kFactorCounts.at(biggerDigit)));
        // Check if the replacement is possible within the available space.
        if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {
          // Fill extra space with '1', if any, and construct the result.
          const int fillOnes =
              spaceAfterThisDigit - sumValues(factorsAfterReplacement);
          return num.substr(0, i) +        // Keep the prefix unchanged.
                 to_string(biggerDigit) +  // Replace the current digit.
                 string(fillOnes, '1') +   // Fill remaining space with '1'.
                 consturct(factorsAfterReplacement);
        }
      }
    }

    // No solution of the same length exists, so we need to extend the number
    // by prepending '1's and adding the required factors.
    const unordered_map<int, int> factorsAfterExtension =
        getFactorCount(primeCount);
    return string(num.length() + 1 - sumValues(factorsAfterExtension), '1') +
           consturct(factorsAfterExtension);
  }

 private:
  constexpr static unordered_map<int, unordered_map<int, int>> kFactorCounts = {
      {0, {}},       {1, {}},       {2, {{2, 1}}},         {3, {{3, 1}}},
      {4, {{2, 2}}}, {5, {{5, 1}}}, {6, {{2, 1}, {3, 1}}}, {7, {{7, 1}}},
      {8, {{2, 3}}}, {9, {{3, 2}}}};

  // Returns the prime count of t and if t is divisible by 2, 3, 5, 7.
  pair<unordered_map<int, int>, bool> getPrimeCount(long t) {
    unordered_map<int, int> count{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
    for (const int prime : {2, 3, 5, 7}) {
      while (t % prime == 0) {
        t /= prime;
        ++count[prime];
      }
    }
    return {count, t == 1};
  }

  // Returns the prime count of `num`.
  unordered_map<int, int> getPrimeCount(const string& num) {
    unordered_map<int, int> count{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
    for (const char d : num)
      for (const auto& [prime, freq] : kFactorCounts.at(d - '0'))
        count[prime] += freq;
    return count;
  }

  unordered_map<int, int> getFactorCount(const unordered_map<int, int>& count) {
    unordered_map<int, int> res;
    // 2^3 = 8
    const int count8 = count.at(2) / 3;
    const int remaining2 = count.at(2) % 3;
    // 3^2 = 9
    const int count9 = count.at(3) / 2;
    int count3 = count.at(3) % 2;
    // 2^2 = 4
    int count4 = remaining2 / 2;
    int count2 = remaining2 % 2;
    // Combine 2 and 3 to 6 if both are present.
    int count6 = 0;
    if (count2 == 1 && count3 == 1) {
      count2 = 0;
      count3 = 0;
      count6 = 1;
    }
    // Combine 3 and 4 to 2 and 6 if both are present.
    if (count3 == 1 && count4 == 1) {
      count2 = 1;
      count6 = 1;
      count3 = 0;
      count4 = 0;
    }
    return unordered_map<int, int>{
        {2, count2}, {3, count3},      {4, count4}, {5, count.at(5)},
        {6, count6}, {7, count.at(7)}, {8, count8}, {9, count9}};
  }

  string consturct(const unordered_map<int, int>& factors) {
    string res;
    for (int digit = 2; digit < 10; ++digit)
      res += string(factors.at(digit), '0' + digit);
    return res;
  }

  // Returns true if a is a subset of b.
  bool isSubset(const unordered_map<int, int>& a,
                const unordered_map<int, int>& b) {
    for (const auto& [key, value] : a)
      if (b.at(key) < value)
        return false;
    return true;
  }

  // Returns a - b.
  unordered_map<int, int> substract(unordered_map<int, int> a,
                                    const unordered_map<int, int>& b) {
    for (const auto& [key, value] : b)
      a[key] = max(0, a[key] - value);
    return a;
  }

  // Returns the sum of the values in `count`.
  int sumValues(const unordered_map<int, int>& count) {
    return accumulate(
        count.begin(), count.end(), 0,
        [](int acc, const pair<int, int>& p) { return acc + p.second; });
  }
};
