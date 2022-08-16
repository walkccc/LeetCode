class Solution {
  public int maxRepOpt1(String text) {
    int ans = 0;
    int[] count = new int[26];
    List<int[]> groups = new ArrayList<>();

    for (char c : text.toCharArray())
      ++count[c - 'a'];

    groups.add(new int[] {text.charAt(0), 1});

    for (int i = 1; i < text.length(); ++i)
      if (text.charAt(i) == text.charAt(i - 1))
        ++groups.get(groups.size() - 1)[1];
      else
        groups.add(new int[] {text.charAt(i), 1});

    for (int[] group : groups)
      ans = Math.max(ans, Math.min(group[1] + 1, count[group[0] - 'a']));

    for (int i = 1; i + 1 < groups.size(); ++i)
      if (groups.get(i - 1)[0] == groups.get(i + 1)[0] && groups.get(i)[1] == 1)
        ans = Math.max(ans, Math.min(groups.get(i - 1)[1] + groups.get(i + 1)[1] + 1,
                                     count[groups.get(i - 1)[0] - 'a']));

    return ans;
  }
}
