class UF {
  public UF(List<List<String>> accounts) {
    for (List<String> account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        final String email = account.get(i);
        id.putIfAbsent(email, email);
      }
  }

  public void union(final String u, final String v) {
    id.put(find(u), find(v));
  }

  public String find(final String u) {
    if (u != id.get(u))
      id.put(u, find(id.get(u)));
    return id.get(u);
  }

  private Map<String, String> id = new HashMap<>();
}

class Solution {
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, String> emailToName = new HashMap<>();
    Map<String, TreeSet<String>> idEmailToEmails = new HashMap<>();
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
        final String id = uf.find(account.get(i));
        idEmailToEmails.putIfAbsent(id, new TreeSet<>());
        idEmailToEmails.get(id).add(account.get(i));
      }

    for (final String idEmail : idEmailToEmails.keySet()) {
      List<String> emails = new ArrayList<>(idEmailToEmails.get(idEmail));
      final String name = emailToName.get(idEmail);
      emails.add(0, name);
      ans.add(emails);
    }

    return ans;
  }
}
