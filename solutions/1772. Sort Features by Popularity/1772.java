class Solution {
  public String[] sortFeatures(String[] features, String[] responses) {
    String[] ans = new String[features.length];
    int[][] featCount = new int[features.length][]; // {i: count[features[i]]}
    Map<String, Integer> count = new HashMap<>();

    for (final String res : responses)
      for (final String token : new HashSet<>(Arrays.asList(res.split(" "))))
        count.merge(token, 1, Integer::sum);

    for (int i = 0; i < features.length; ++i)
      featCount[i] = new int[] {i, count.getOrDefault(features[i], 0)};

    Arrays.sort(featCount,
                Comparator.comparingInt((int[] a) -> - a[1]).thenComparingInt((int[] a) -> a[0]));

    for (int i = 0; i < features.length; ++i)
      ans[i] = features[featCount[i][0]];

    return ans;
  }
}
