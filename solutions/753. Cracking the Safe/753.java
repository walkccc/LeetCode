class Solution {
  public String crackSafe(int n, int k) {
    final String allZeros = "0".repeat(n);
    StringBuilder sb = new StringBuilder(allZeros);
    dfs((int) Math.pow(k, n), n, k, new HashSet<>(Arrays.asList(allZeros)), sb);
    return sb.toString();
  }

  private boolean dfs(int passwordSize, int n, int k, Set<String> seen, StringBuilder path) {
    if (seen.size() == passwordSize)
      return true;

    StringBuilder prefix = new StringBuilder(path.substring(path.length() - n + 1));

    for (char c = '0'; c < '0' + k; ++c) {
      prefix.append(c);
      final String prefixStr = prefix.toString();
      if (!seen.contains(prefixStr)) {
        seen.add(prefixStr);
        path.append(c);
        if (dfs(passwordSize, n, k, seen, path))
          return true;
        path.deleteCharAt(path.length() - 1);
        seen.remove(prefixStr);
      }
      prefix.deleteCharAt(prefix.length() - 1);
    }

    return false;
  }
}
