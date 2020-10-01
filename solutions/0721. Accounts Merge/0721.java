class Solution {
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, String> emailToName = new HashMap<>();
    Map<String, TreeSet<String>> groups = new HashMap<>();
    UF uf = new UF(accounts);

    for (final List<String> account : accounts)
      for (int i = 1; i < account.size(); ++i)
        emailToName.putIfAbsent(account.get(i), account.get(0));

    for (final List<String> account : accounts)
      for (int i = 2; i < account.size(); ++i)
        uf.union(account.get(i), account.get(i - 1));

    for (final List<String> account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        final String parent = uf.find(account.get(i));
        groups.computeIfAbsent(parent, k -> new TreeSet<>()).add(account.get(i));
      }

    for (final String parent : groups.keySet()) {
      List<String> emails = new ArrayList<>(groups.get(parent));
      final String name = emailToName.get(parent);
      emails.add(0, name);
      ans.add(emails);
    }

    return ans;
  }
}

class UF {
  public UF(List<List<String>> accounts) {
    for (List<String> account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        rank.putIfAbsent(account.get(i), 0);
        parent.putIfAbsent(account.get(i), account.get(i));
      }
  }

  public void union(final String u, final String v) {
    final String pu = find(u);
    final String pv = find(v);
    if (pu == pv)
      return;

    if (rank.get(pu) < rank.get(pv))
      parent.put(pu, pv);
    else if (rank.get(pu) > rank.get(pv))
      parent.put(pv, pu);
    else {
      parent.put(pu, pv);
      rank.put(pv, rank.get(pv) + 1);
    }
  }

  public String find(final String u) {
    if (parent.get(u) != u)
      parent.put(u, find(parent.get(u)));
    return parent.get(u);
  }

  private Map<String, Integer> rank = new HashMap<>();
  private Map<String, String> parent = new HashMap<>();
}