class Solution {
  public int[][] reconstructQueue(int[][] people) {
    List<int[]> ans = new ArrayList<>();

    Arrays.sort(people, Comparator.comparingInt((int[] person) -> - person[0])
                            .thenComparingInt((int[] person) -> person[1]));

    for (final int[] person : people)
      ans.add(person[1], person);

    return ans.stream().toArray(int[][] ::new);
  }
}
