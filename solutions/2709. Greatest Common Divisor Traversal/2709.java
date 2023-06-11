class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    sz = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
    for (int i = 0; i < n; ++i)
      sz[i] = 1;
  }

  public void unionBySize(int u, int v) {
    final int i = find(u);
    final int j = find(v);
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

  public int getSize(int i) {
    return sz[i];
  }

  private int[] id;
  private int[] sz;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public boolean canTraverseAllPairs(int[] nums) {
    final int n = nums.length;
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    final int[] minPrimeFactor = sieveEratosthenes(maxNum + 1);
    Map<Integer, Integer> primeToFirstIndex = new HashMap<>();
    UnionFind uf = new UnionFind(n);

    for (int i = 0; i < n; ++i)
      for (final int primeFactor : getPrimeFactors(nums[i], minPrimeFactor))
        // `primeFactor` already appeared in the previous indices.
        if (primeToFirstIndex.containsKey(primeFactor))
          uf.unionBySize(primeToFirstIndex.get(primeFactor), i);
        else
          primeToFirstIndex.put(primeFactor, i);

    for (int i = 0; i < n; ++i)
      if (uf.getSize(i) == n)
        return true;
    return false;
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
