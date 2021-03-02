class UF {
  public UF(List<List<String>> accounts) {
    for (List<String> account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        final String email = account.get(i);
        parent.putIfAbsent(email, email);
      }
  }

  public void union(final String u, final String v) {
    parent.put(find(u), find(v));
  }

  public String find(final String u) {
    if (u != parent.get(u))
      parent.put(u, find(parent.get(u)));
    return parent.get(u);
  }

  private Map<String, String> parent = new HashMap<>();
}

class Solution {
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, String> emailToName = new HashMap<>();
    Map<String, TreeSet<String>> parentEmailToEmails = new HashMap<>();
    UF uf = new UF(accounts);

    // get {email: name} mapping
    for (final List<String> account : accounts)
      for (int i = 1; i < account.size(); ++i)
        emailToName.putIfAbsent(account.get(i), account.get(0));

    // union emails
    for (final List<String> account : accounts)
      for (int i = 2; i < account.size(); ++i)
        uf.union(account.get(i), account.get(i - 1));

    for (final List<String> account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        final String parent = uf.find(account.get(i));
        parentEmailToEmails.putIfAbsent(parent, new TreeSet<>());
        parentEmailToEmails.get(parent).add(account.get(i));
      }

    for (final String parentEmail : parentEmailToEmails.keySet()) {
      List<String> emails = new ArrayList<>(parentEmailToEmails.get(parentEmail));
      final String name = emailToName.get(parentEmail);
      emails.add(0, name);
      ans.add(emails);
    }

    return ans;
  }
}
