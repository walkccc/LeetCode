class Solution {
  public String[] findOcurrences(String text, String first, String second) {
    List<String> ans = new ArrayList<>();
    String[] words = text.split(" ");

    for (int i = 0; i + 2 < words.length; ++i)
      if (first.equals(words[i]) && second.equals(words[i + 1]))
        ans.add(words[i + 2]);

    return ans.toArray(new String[0]);
  }
}
