class Solution {
  public int[][] reconstructQueue(int[][] people) {
    List<int[]> ans = new ArrayList<>();

    Arrays.sort(people,
                (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(b[0], a[0]));

    for (final int[] p : people)
      ans.add(p[1], p);

    return ans.stream().toArray(int[][] ::new);
  }
}
