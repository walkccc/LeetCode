class UnionFind {
 public:
  UnionFind(int n) : id(n), sz(n, 1) {
    iota(id.begin(), id.end(), 0);
  }

  void unionBySize(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (sz[i] < sz[j]) {
      sz[j] += sz[i];
      id[i] = j;
    } else {
      sz[i] += sz[j];
      id[j] = i;
    }
  }

  int getSize(int i) {
    return sz[i];
  }

 private:
  vector<int> id;
  vector<int> sz;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  bool canTraverseAllPairs(vector<int>& nums) {
    const int n = nums.size();
    const int maxNum = ranges::max(nums);
    const vector<int> minPrimeFactors = sieveEratosthenes(maxNum + 1);
    unordered_map<int, int> primeToFirstIndex;
    UnionFind uf(n);

    for (int i = 0; i < n; ++i)
      for (const int primeFactor : getPrimeFactors(nums[i], minPrimeFactors))
        // `primeFactor` already appeared in the previous indices.
        if (const auto it = primeToFirstIndex.find(primeFactor);
            it != primeToFirstIndex.cend())
          uf.unionBySize(it->second, i);
        else
          primeToFirstIndex[primeFactor] = i;

    for (int i = 0; i < n; ++i)
      if (uf.getSize(i) == n)
        return true;

    return false;
  }

 private:
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

  vector<int> getPrimeFactors(int num, const vector<int>& minPrimeFactors) {
    vector<int> primeFactors;
    while (num > 1) {
      const int divisor = minPrimeFactors[num];
      primeFactors.push_back(divisor);
      while (num % divisor == 0)
        num /= divisor;
    }
    return primeFactors;
  }
};
