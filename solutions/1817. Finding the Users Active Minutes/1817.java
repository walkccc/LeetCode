class Solution {
  public int[] findingUsersActiveMinutes(int[][] logs, int k) {
    int[] ans = new int[k];
    Map<Integer, Set<Integer>> idToTimes = new HashMap<>();

    for (int[] log : logs) {
      idToTimes.putIfAbsent(log[0], new HashSet<>());
      idToTimes.get(log[0]).add(log[1]);
    }

    for (final int id : idToTimes.keySet())
      ++ans[idToTimes.get(id).size() - 1];

    return ans;
  }
}
