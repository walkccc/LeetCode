class Solution {
  public List<List<String>> findDuplicate(String[] paths) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, List<String>> files = new HashMap<>();

    for (final String path : paths) {
      String[] words = path.split(" ");
      String root = words[0];
      for (int i = 1; i < words.length; ++i) {
        final String s = words[i];
        String filePath = root + '/' + s.substring(0, s.indexOf('('));
        String fileContent = s.substring(s.indexOf('(') + 1, s.indexOf(')'));
        if (!files.containsKey(fileContent))
          files.put(fileContent, new ArrayList<>());
        files.get(fileContent).add(filePath);
      }
    }

    for (List<String> filePath : files.values())
      if (filePath.size() > 1)
        ans.add(filePath);

    return ans;
  }
}