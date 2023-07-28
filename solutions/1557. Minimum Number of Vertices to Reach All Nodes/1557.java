class Solution {
  public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
    List<Integer> ans = new ArrayList<>();
    int[] inDegree = new int[n];

    for (List<Integer> edge : edges)
      ++inDegree[edge.get(1)];

    for (int i = 0; i < inDegree.length; ++i)
      if (inDegree[i] == 0)
        ans.add(i);

    return ans;
  }
}
