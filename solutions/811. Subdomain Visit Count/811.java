class Solution {
  public List<String> subdomainVisits(String[] cpdomains) {
    List<String> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();

    for (final String cpdomain : cpdomains) {
      final int space = cpdomain.indexOf(' ');
      final int num = Integer.valueOf(cpdomain.substring(0, space));
      final String domain = cpdomain.substring(space + 1);
      count.merge(domain, num, Integer::sum);
      for (int i = 0; i < domain.length(); ++i)
        if (domain.charAt(i) == '.') {
          String subdomain = domain.substring(i + 1);
          count.merge(subdomain, num, Integer::sum);
        }
    }

    for (final String subdomain : count.keySet())
      ans.add(String.valueOf(count.get(subdomain)) + ' ' + subdomain);

    return ans;
  }
}
