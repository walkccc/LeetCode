class Solution {
  public double[] calcEquation(List<List<String>> equations, double[] values,
                               List<List<String>> queries) {
    double[] ans = new double[queries.size()];
    // graph.get(A).get(B) := A / B
    Map<String, Map<String, Double>> graph = new HashMap<>();

    // Construct the graph.
    for (int i = 0; i < equations.size(); ++i) {
      final String A = equations.get(i).get(0);
      final String B = equations.get(i).get(1);
      graph.putIfAbsent(A, new HashMap<>());
      graph.putIfAbsent(B, new HashMap<>());
      graph.get(A).put(B, values[i]);
      graph.get(B).put(A, 1.0 / values[i]);
    }

    for (int i = 0; i < queries.size(); ++i) {
      final String A = queries.get(i).get(0);
      final String C = queries.get(i).get(1);
      if (!graph.containsKey(A) || !graph.containsKey(C))
        ans[i] = -1.0;
      else
        ans[i] = divide(graph, A, C, new HashSet<>());
    }

    return ans;
  }

  // Returns A / C.
  private double divide(Map<String, Map<String, Double>> graph, final String A, final String C,
                        Set<String> seen) {
    if (A.equals(C))
      return 1.0;

    seen.add(A);

    for (final String B : graph.get(A).keySet()) {
      if (seen.contains(B))
        continue;
      final double res = divide(graph, B, C, seen); // B / C
      if (res > 0)                                  // valid result
        return graph.get(A).get(B) * res;           // A / C = (A / B) * (B / C)
    }

    return -1.0; // invalid result
  }
}
