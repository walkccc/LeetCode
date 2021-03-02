class Solution {
  public List<List<String>> findDuplicate(String[] paths) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, List<String>> files = new HashMap<>();

    for (final String path : paths) {
      final String[] words = path.split(" ");
      final String rootPath = words[0];
      for (int i = 1; i < words.length; ++i) {
        final String fileContent = words[i];
        final int l = fileContent.indexOf('(');
        final int r = fileContent.indexOf(')');
        // "fn.txt"
        final String file = fileContent.substring(0, l);
        // "root/d1/d2/.../fn.txt"
        final String filePath = rootPath + '/' + file;
        // "fn_content"
        final String content = fileContent.substring(l + 1, r);
        files.putIfAbsent(content, new ArrayList<>());
        files.get(content).add(filePath);
      }
    }

    for (List<String> filePath : files.values())
      if (filePath.size() > 1)
        ans.add(filePath);

    return ans;
  }
}
