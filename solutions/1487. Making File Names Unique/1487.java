class Solution {
  public String[] getFolderNames(String[] names) {
    String[] ans = new String[names.length];
    Map<String, Integer> nameToSuffix = new HashMap<>();

    for (int i = 0; i < names.length; ++i) {
      final String name = names[i];
      if (nameToSuffix.containsKey(name)) {
        int suffix = nameToSuffix.get(name);
        String newName = getName(name, ++suffix);
        while (nameToSuffix.containsKey(newName))
          newName = getName(name, ++suffix);
        nameToSuffix.put(name, suffix);
        nameToSuffix.put(newName, 0);
        ans[i] = newName;
      } else {
        nameToSuffix.put(name, 0);
        ans[i] = name;
      }
    }

    return ans;
  }

  private String getName(final String name, int suffix) {
    return name + "(" + String.valueOf(suffix) + ")";
  }
}
