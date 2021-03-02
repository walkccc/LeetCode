class Solution {
  public int maximumRequests(int n, int[][] requests) {
    dfs(0, 0, requests, new int[n]);

    return ans;
  }

  private int ans = 0;

  private void dfs(int i, int processedReqs, int[][] requests, int[] degree) {
    if (i == requests.length) {
      if (Arrays.stream(degree).allMatch(d -> d == 0))
        ans = Math.max(ans, processedReqs);
      return;
    }

    // skip requests[i]
    dfs(i + 1, processedReqs, requests, degree);

    // process requests[i]
    --degree[requests[i][0]];
    ++degree[requests[i][1]];
    dfs(i + 1, processedReqs + 1, requests, degree);
    --degree[requests[i][1]];
    ++degree[requests[i][0]];
  }
}
