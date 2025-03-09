class Solution {
  public List<String> alertNames(String[] keyName, String[] keyTime) {
    List<String> ans = new ArrayList<>();
    HashMap<String, List<Integer>> nameToMinutes = new HashMap<>();

    for (int i = 0; i < keyName.length; i++) {
      final int minutes = getMinutes(keyTime[i]);
      nameToMinutes.putIfAbsent(keyName[i], new ArrayList<>());
      nameToMinutes.get(keyName[i]).add(minutes);
    }

    for (Map.Entry<String, List<Integer>> entry : nameToMinutes.entrySet()) {
      final String name = entry.getKey();
      List<Integer> minutes = entry.getValue();
      if (hasAlert(minutes))
        ans.add(name);
    }

    Collections.sort(ans);
    return ans;
  }

  private boolean hasAlert(List<Integer> minutes) {
    if (minutes.size() > 70)
      return true;
    Collections.sort(minutes);
    for (int i = 2; i < minutes.size(); i++)
      if (minutes.get(i - 2) + 60 >= minutes.get(i))
        return true;
    return false;
  }

  private int getMinutes(String time) {
    final int h = Integer.parseInt(time.substring(0, 2));
    final int m = Integer.parseInt(time.substring(3));
    return 60 * h + m;
  }
}
