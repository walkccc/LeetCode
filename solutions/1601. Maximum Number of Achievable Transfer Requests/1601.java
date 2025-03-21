class Solution {
  public int maximumRequests(int n, int[][] requests) {
    dfs(0, 0, requests, new int[n]);

    return ans;
  }

  private int ans = 0;

  private void dfs(int i, int processedReqs, int[][] requests, int[] degrees) {
    if (i == requests.length) {
      if (Arrays.stream(degrees).allMatch(d -> d == 0))
        ans = Math.max(ans, processedReqs);
      return;
    }

    // Skip the requests[i].
    dfs(i + 1, processedReqs, requests, degrees);

    // Process the requests[i].
    --degrees[requests[i][0]];
    ++degrees[requests[i][1]];
    dfs(i + 1, processedReqs + 1, requests, degrees);
    --degrees[requests[i][1]];
    ++degrees[requests[i][0]];
  }
}
