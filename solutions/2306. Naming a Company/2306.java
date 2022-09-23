class Solution {
  public long distinctNames(String[] ideas) {
    long ans = 0;
    // group strings by initials
    Set<String>[] suffixes = new Set[26];

    for (int i = 0; i < 26; ++i)
      suffixes[i] = new HashSet<>();

    for (final String idea : ideas)
      suffixes[idea.charAt(0) - 'a'].add(idea.substring(1));

    for (int i = 0; i < 25; ++i)
      for (int j = i + 1; j < 26; ++j) {
        int count = 0;
        for (final String suffix : suffixes[i])
          if (suffixes[j].contains(suffix))
            ++count;
        ans += 2 * (suffixes[i].size() - count) * (suffixes[j].size() - count);
      }

    return ans;
  }
}
