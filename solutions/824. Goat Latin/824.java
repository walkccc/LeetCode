class Solution {
  public String toGoatLatin(String sentence) {
    StringBuilder sb = new StringBuilder();

    int i = 1;
    for (final String word : sentence.split(" ")) {
      if (i > 1)
        sb.append(" ");
      if (isVowel(word.charAt(0)))
        sb.append(word);
      else
        sb.append(word.substring(1) + word.charAt(0));
      sb.append("ma").append("a".repeat(i++));
    }

    return sb.toString();
  }

  private boolean isVowel(char c) {
    return "aeiouAEIOU".indexOf(c) != -1;
  }
}
