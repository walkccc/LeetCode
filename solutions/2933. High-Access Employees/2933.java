class Solution {
  public List<String> findHighAccessEmployees(List<List<String>> access_times) {
    Set<String> ans = new HashSet<>();

    Collections.sort(access_times,
                     (a, b)
                         -> a.get(0).equals(b.get(0)) ? a.get(1).compareTo(b.get(1))
                                                      : a.get(0).compareTo(b.get(0)));

    for (int i = 0; i + 2 < access_times.size(); ++i) {
      String name = access_times.get(i).get(0);
      if (ans.contains(name))
        continue;
      if (!name.equals(access_times.get(i + 2).get(0)))
        continue;
      if (Integer.parseInt(access_times.get(i + 2).get(1)) -
              Integer.parseInt(access_times.get(i).get(1)) <
          100)
        ans.add(name);
    }

    return new ArrayList<>(ans);
  }
}
