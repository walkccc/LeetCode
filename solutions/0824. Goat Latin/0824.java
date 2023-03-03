class Solution {
  public String toGoatLatin(String s) {
    String ans = "";
    final String vowels = "aeiouAEIOU";
    final String[] words = s.split(" ");
    int i = 1;

    for (final String word : words) {
      if (i > 1)
        ans += " ";
      if (vowels.contains("" + word.charAt(0)))
        ans += word;
      else
        ans += word.substring(1) + word.charAt(0);
      ans += "ma"
             + "a".repeat(i++);
    }

    return ans;
  }
}
