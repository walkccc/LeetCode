class Solution {
  public int[] restoreArray(int[][] adjacentPairs) {
    int[] ans = new int[adjacentPairs.length + 1];
    int i = 0; // ans' index
    Map<Integer, List<Integer>> numToAdjs = new HashMap<>();

    for (int[] pair : adjacentPairs) {
      numToAdjs.putIfAbsent(pair[0], new ArrayList<>());
      numToAdjs.putIfAbsent(pair[1], new ArrayList<>());
      numToAdjs.get(pair[0]).add(pair[1]);
      numToAdjs.get(pair[1]).add(pair[0]);
    }

    for (Map.Entry<Integer, List<Integer>> entry : numToAdjs.entrySet())
      if (entry.getValue().size() == 1) {
        ans[i++] = entry.getKey();
        ans[i++] = entry.getValue().get(0);
        break;
      }

    while (i < adjacentPairs.length + 1) {
      final int tail = ans[i - 1];
      final int prev = ans[i - 2];
      List<Integer> adjs = numToAdjs.get(tail);
      if (adjs.get(0) == prev)
        ans[i++] = adjs.get(1);
      else
        ans[i++] = adjs.get(0);
    }

    return ans;
  }
}
