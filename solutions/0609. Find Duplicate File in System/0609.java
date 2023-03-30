class Solution {
  public List<List<String>> findDuplicate(String[] paths) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, List<String>> contentToFilePaths = new HashMap<>();

    for (final String path : paths) {
      final String[] words = path.split(" ");
      final String rootPath = words[0]; // "root/d1/d2/.../dm"
      for (int i = 1; i < words.length; ++i) {
        final String fileAndContent = words[i]; // "fn.txt(fn_content)"
        final int l = fileAndContent.indexOf('(');
        final int r = fileAndContent.indexOf(')');
        // "fn.txt"
        final String file = fileAndContent.substring(0, l);
        // "fn_content"
        final String content = fileAndContent.substring(l + 1, r);
        // "root/d1/d2/.../dm/fn.txt"
        final String filePath = rootPath + '/' + file;
        contentToFilePaths.putIfAbsent(content, new ArrayList<>());
        contentToFilePaths.get(content).add(filePath);
      }
    }

    for (List<String> filePaths : contentToFilePaths.values())
      if (filePaths.size() > 1)
        ans.add(filePaths);

    return ans;
  }
}
