class Solution {
  public boolean checkContradictions(List<List<String>> equations, double[] values) {
    // Convert `string` to `int` for a better perfermance.
    Map<String, Integer> strToInt = new HashMap<>();

    for (List<String> equation : equations) {
      strToInt.putIfAbsent(equation.get(0), strToInt.size());
      strToInt.putIfAbsent(equation.get(1), strToInt.size());
    }

    List<Pair<Integer, Double>>[] graph = new List[strToInt.size()];
    double[] seen = new double[graph.length];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 0; i < equations.size(); ++i) {
      final int u = strToInt.get(equations.get(i).get(0));
      final int v = strToInt.get(equations.get(i).get(1));
      graph[u].add(new Pair<>(v, values[i]));
      graph[v].add(new Pair<>(u, 1 / values[i]));
    }

    for (int i = 0; i < graph.length; ++i)
      if (seen[i] != 0.0 && dfs(graph, i, seen, 1.0))
        return true;

    return false;
  }

  private boolean dfs(List<Pair<Integer, Double>>[] graph, int u, double[] seen, double val) {
    if (seen[u] != 0.0)
      return Math.abs(val / seen[u] - 1) > 1e-5;

    seen[u] = val;
    for (Pair<Integer, Integer> pair : graph[u]) {
      final int v = pair.getKey();
      final double w = pair.getValue();
      if (dfs(graph, v, seen, val / w))
        return true;
    }

    return false;
  }
}
