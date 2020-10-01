class Solution {
  public String crackSafe(int n, int k) {
    passwordSize = (int) Math.pow(k, n);
    String path = new String(new char[n]).replace('\0', '0');
    Set<String> seen = new HashSet<>(Arrays.asList(path));

    dfs(n, k, seen, path);

    return ans;
  }

  private String ans;
  private Integer passwordSize;

  private boolean dfs(int n, int k, Set<String> seen, String path) {
    if (seen.size() == passwordSize) {
      ans = path;
      return true;
    }

    String prefix = path.substring(path.length() - n + 1);

    for (char c = '0'; c < '0' + k; ++c) {
      String next = prefix + c;
      if (!seen.contains(next)) {
        seen.add(next);
        if (dfs(n, k, seen, path + c))
          return true;
        seen.remove(next);
      }
    }

    return false;
  }
}