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
      id[i] = id[j];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
    } else {
      id[i] = id[j];
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
    final int[] minPrimeFactor = sieveEratosthenes(maxNum + 1);
    UnionFind uf = new UnionFind(maxNum + 1);

    for (final int num : nums)
      for (final int primeFactor : getPrimeFactors(num, minPrimeFactor))
        uf.unionByRank(num, primeFactor);

    int[] sortedNums = nums.clone();
    Arrays.sort(sortedNums);

    for (int i = 0; i < nums.length; ++i)
      // Can't swap nums[i] with sortedNums[i].
      if (uf.find(nums[i]) != uf.find(sortedNums[i]))
        return false;

    return true;
  }

  // Gets min prime factor of i, where 1 < i <= n.
  private int[] sieveEratosthenes(int n) {
    int[] minPrimeFactor = new int[n + 1];
    for (int i = 2; i <= n; ++i)
      minPrimeFactor[i] = i;
    for (int i = 2; i * i < n; ++i)
      if (minPrimeFactor[i] == i) // `i` is prime.
        for (int j = i * i; j < n; j += i)
          minPrimeFactor[j] = Math.min(minPrimeFactor[j], i);
    return minPrimeFactor;
  }

  private List<Integer> getPrimeFactors(int num, int[] minPrimeFactor) {
    List<Integer> primeFactors = new ArrayList<>();
    while (num > 1) {
      final int divisor = minPrimeFactor[num];
      primeFactors.add(divisor);
      while (num % divisor == 0)
        num /= divisor;
    }
    return primeFactors;
  }
}
