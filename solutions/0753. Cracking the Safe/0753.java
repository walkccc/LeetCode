class Solution {
  public String crackSafe(int n, int k) {
    passwordSize = (int) Math.pow(k, n);
    String allZeros = new String(new char[n]).replace('\0', '0');
    Set<String> seen = new HashSet<>(Arrays.asList(allZeros));
    StringBuilder sb = new StringBuilder(allZeros);

    dfs(n, k, seen, sb);

    return sb.toString();
  }

  private int passwordSize;

  private boolean dfs(int n, int k, Set<String> seen, StringBuilder path) {
    if (seen.size() == passwordSize)
      return true;

    StringBuilder prefix = new StringBuilder(path.substring(path.length() - n + 1));

    for (char c = '0'; c < '0' + k; ++c) {
      prefix.append(c);
      final String prefixStr = prefix.toString();
      if (!seen.contains(prefixStr)) {
        seen.add(prefixStr);
        path.append(c);
        if (dfs(n, k, seen, path))
          return true;
        path.deleteCharAt(path.length() - 1);
        seen.remove(prefixStr);
      }
      prefix.deleteCharAt(prefix.length() - 1);
    }

    return false;
  }
}
