class Solution {
 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<int> degrees(n);

    for (const vector<int>& road : roads) {
      const int u = road[0];
      const int v = road[1];
      ++degrees[u];
      ++degrees[v];
    }

    // Find the first maximum and the second maximum degrees.
    int maxDegree1 = 0;
    int maxDegree2 = 0;
    for (const int degree : degrees) {
      if (degree > maxDegree1) {
        maxDegree2 = maxDegree1;
        maxDegree1 = degree;
      } else if (degree > maxDegree2) {
        maxDegree2 = degree;
      }
    }

    // There can be multiple nodes with the `maxDegree1` or the `maxDegree2`.
    // Find the counts of such nodes.
    int countMaxDegree1 = 0;
    int countMaxDegree2 = 0;
    for (const int degree : degrees)
      if (degree == maxDegree1)
        ++countMaxDegree1;
      else if (degree == maxDegree2)
        ++countMaxDegree2;

    if (countMaxDegree1 == 1) {
      // Case 1: If there is only one node with degree = `maxDegree1`, then
      // we'll need to use the node with degree = `maxDegree2`. The answer in
      // general will be (maxDegree1 + maxDegree2), but if the two nodes that
      // we're considering are connected, then we'll have to subtract 1.
      const int edgeCount =
          getEdgeCount(roads, degrees, maxDegree1, maxDegree2) +
          getEdgeCount(roads, degrees, maxDegree2, maxDegree1);
      return maxDegree1 + maxDegree2 - (countMaxDegree2 == edgeCount ? 1 : 0);
    } else {
      // Case 2: If there are more than one node with degree = `maxDegree1`,
      // then we can consider `maxDegree1` twice, and we don't need to use
      // `maxDegree2`. The answer in general will be 2 * maxDegree1, but if the
      // two nodes that we're considering are connected, then we'll have to
      // subtract 1.
      const int edgeCount =
          getEdgeCount(roads, degrees, maxDegree1, maxDegree1);
      const int maxPossibleEdgeCount =
          countMaxDegree1 * (countMaxDegree1 - 1) / 2;
      return 2 * maxDegree1 - (maxPossibleEdgeCount == edgeCount ? 1 : 0);
    }
  }

 private:
  // Returns the number of edges (u, v) where degress[u] == degreeU and
  // degrees[v] == degreeV.
  int getEdgeCount(const vector<vector<int>>& roads, const vector<int>& degrees,
                   int degreeU, int degreeV) {
    int edgeCount = 0;
    for (const vector<int>& road : roads) {
      const int u = road[0];
      const int v = road[1];
      if (degrees[u] == degreeU && degrees[v] == degreeV)
        ++edgeCount;
    }
    return edgeCount;
  }
};
