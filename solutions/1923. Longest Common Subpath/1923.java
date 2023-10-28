class Solution {
  public int longestCommonSubpath(int n, int[][] paths) {
    int l = 0;
    int r = paths[0].length;

    while (l < r) {
      final int m = l + (r - l + 1) / 2;
      if (checkCommonSubpath(paths, m))
        l = m;
      else
        r = m - 1;
    }

    return l;
  }

  private static final long kMod = 8_417_508_174_513L;
  private static final long kBase = 165_131L;

  // Returns true if there exists a common subpath of length m for all paths.
  private boolean checkCommonSubpath(int[][] paths, int m) {
    Set<Long>[] hashSets = new Set[paths.length];

    // Calculate the hash values for subpaths of length m for every path.
    for (int i = 0; i < paths.length; ++i)
      hashSets[i] = rabinKarp(paths[i], m);

    // Check if there is a common subpath of length m.
    for (final long subpathHash : hashSets[0])
      if (Arrays.stream(hashSets).allMatch(hashSet -> hashSet.contains(subpathHash)))
        return true;

    return false;
  }

  // Returns hash values for subpaths of length m in the path.
  private Set<Long> rabinKarp(int[] path, int m) {
    Set<Long> hashes = new HashSet<>();
    long maxPower = 1;
    long hash = 0;
    for (int i = 0; i < path.length; ++i) {
      hash = (hash * kBase + path[i]) % kMod;
      if (i >= m)
        hash = (hash - path[i - m] * maxPower % kMod + kMod) % kMod;
      else
        maxPower = maxPower * kBase % kMod;
      if (i >= m - 1)
        hashes.add(hash);
    }
    return hashes;
  }
}
