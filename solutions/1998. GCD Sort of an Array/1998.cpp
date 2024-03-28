class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  bool gcdSort(vector<int>& nums) {
    const int maxNum = ranges::max(nums);
    const vector<int> minPrimeFactors = sieveEratosthenes(maxNum + 1);
    UnionFind uf(maxNum + 1);

    for (const int num : nums)
      for (const int primeFactor : getPrimeFactors(num, minPrimeFactors))
        uf.unionByRank(num, primeFactor);

    vector<int> sortedNums(nums);
    ranges::sort(sortedNums);

    for (int i = 0; i < nums.size(); ++i)
      // Can't swap nums[i] with sortedNums[i].
      if (uf.find(nums[i]) != uf.find(sortedNums[i]))
        return false;

    return true;
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
