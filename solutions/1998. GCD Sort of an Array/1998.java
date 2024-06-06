class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void unionByRank(int u, int v) {
    final int i = find(u);
    final int j = find(v);
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

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
  private int[] rank;
}

class Solution {
  public boolean gcdSort(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    final int[] minPrimeFactors = sieveEratosthenes(maxNum + 1);
    UnionFind uf = new UnionFind(maxNum + 1);

    for (final int num : nums)
      for (final int primeFactor : getPrimeFactors(num, minPrimeFactors))
        uf.unionByRank(num, primeFactor);

    int[] sortedNums = nums.clone();
    Arrays.sort(sortedNums);

    for (int i = 0; i < nums.length; ++i)
      // Can't swap nums[i] with sortedNums[i].
      if (uf.find(nums[i]) != uf.find(sortedNums[i]))
        return false;

    return true;
  }

  // Gets the minimum prime factor of i, where 1 < i <= n.
  private int[] sieveEratosthenes(int n) {
    int[] minPrimeFactors = new int[n + 1];
    for (int i = 2; i <= n; ++i)
      minPrimeFactors[i] = i;
    for (int i = 2; i * i < n; ++i)
      if (minPrimeFactors[i] == i) // `i` is prime.
        for (int j = i * i; j < n; j += i)
          minPrimeFactors[j] = Math.min(minPrimeFactors[j], i);
    return minPrimeFactors;
  }

  private List<Integer> getPrimeFactors(int num, int[] minPrimeFactors) {
    List<Integer> primeFactors = new ArrayList<>();
    while (num > 1) {
      final int divisor = minPrimeFactors[num];
      primeFactors.add(divisor);
      while (num % divisor == 0)
        num /= divisor;
    }
    return primeFactors;
  }
}
