class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    const int k = primes.size();
    vector<int> indices(k);
    vector<int> uglyNums{1};

    while (uglyNums.size() < n) {
      vector<int> nexts(k);
      for (int i = 0; i < k; ++i)
        nexts[i] = uglyNums[indices[i]] * primes[i];
      const int next = *min_element(begin(nexts), end(nexts));
      for (int i = 0; i < k; ++i)
        if (next == nexts[i])
          ++indices[i];
      uglyNums.push_back(next);
    }

    return uglyNums.back();
  }
};
