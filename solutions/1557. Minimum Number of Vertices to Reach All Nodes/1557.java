class Solution {
  public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
    List<Integer> ans = new ArrayList<>();
    int[] inDegrees = new int[n];

    for (List<Integer> edge : edges)
      ++inDegrees[edge.get(1)];

    for (int i = 0; i < inDegrees.length; ++i)
      if (inDegrees[i] == 0)
        ans.add(i);

    return ans;
  }
}
