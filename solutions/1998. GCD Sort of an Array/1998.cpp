class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(begin(id), end(id), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
    } else {
      id[i] = id[j];
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
    const int maxNum = *max_element(begin(nums), end(nums));
    const vector<int> minPrimeFactor = sieveEratosthenes(maxNum + 1);
    UnionFind uf(maxNum + 1);

    for (const int num : nums)
      for (const int primeFactor : getPrimeFactors(num, minPrimeFactor))
        uf.unionByRank(num, primeFactor);

    vector<int> sortedNums(nums);
    sort(begin(sortedNums), end(sortedNums));

    for (int i = 0; i < nums.size(); ++i)
      // Can't swap nums[i] with sortedNums[i].
      if (uf.find(nums[i]) != uf.find(sortedNums[i]))
        return false;

    return true;
  }

 private:
  // Gets min prime factor of i, where 1 < i <= n.
  vector<int> sieveEratosthenes(int n) {
    vector<int> minPrimeFactor(n + 1);
    iota(begin(minPrimeFactor) + 2, end(minPrimeFactor), 2);
    for (int i = 2; i * i < n; ++i)
      if (minPrimeFactor[i] == i)  // `i` is prime.
        for (int j = i * i; j < n; j += i)
          minPrimeFactor[j] = min(minPrimeFactor[j], i);
    return minPrimeFactor;
  }

  vector<int> getPrimeFactors(int num, const vector<int>& minPrimeFactor) {
    vector<int> primeFactors;
    while (num > 1) {
      const int divisor = minPrimeFactor[num];
      primeFactors.push_back(divisor);
      while (num % divisor == 0)
        num /= divisor;
    }
    return primeFactors;
  }
};
