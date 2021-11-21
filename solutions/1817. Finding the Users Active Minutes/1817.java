class Solution {
  public int[] findingUsersActiveMinutes(int[][] logs, int k) {
    int[] ans = new int[k];
    Map<Integer, Set<Integer>> idToTimes = new HashMap<>();

    for (int[] l : logs) {
      idToTimes.putIfAbsent(l[0], new HashSet<>());
      idToTimes.get(l[0]).add(l[1]);
    }

    for (final int id : idToTimes.keySet())
      ++ans[idToTimes.get(id).size() - 1];

    return ans;
  }
}
