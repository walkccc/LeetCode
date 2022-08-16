class Solution {
  public String[] sortFeatures(String[] features, String[] responses) {
    String[] ans = new String[features.length];
    int[][] featCount = new int[features.length][]; // {i: count[features[i]]}
    Map<String, Integer> count = new HashMap<>();

    for (final String res : responses)
      for (final String token : new HashSet<>(Arrays.asList(res.split(" "))))
        count.put(token, count.getOrDefault(token, 0) + 1);

    for (int i = 0; i < features.length; ++i)
      featCount[i] = new int[] {i, count.getOrDefault(features[i], 0)};

    Arrays.sort(featCount, (a, b) -> a[1] == b[1] ? a[0] - b[0] : b[1] - a[1]);

    for (int i = 0; i < features.length; ++i)
      ans[i] = features[featCount[i][0]];

    return ans;
  }
}
