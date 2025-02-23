class Solution {
  public int edgeScore(int[] edges) {
    int ans = 0;
    long[] scores = new long[edges.length];

    for (int i = 0; i < edges.length; ++i)
      scores[edges[i]] += i;

    for (int i = 1; i < scores.length; ++i)
      if (scores[i] > scores[ans])
        ans = i;

    return ans;
  }
}
