class Solution {
  public String sortVowels(String s) {
    StringBuilder sb = new StringBuilder();
    List<Character> vowels = new ArrayList<>();

    for (final char c : s.toCharArray())
      if (isVowel(c))
        vowels.add(c);

    Collections.sort(vowels);

    int i = 0; // vowels' index
    for (final char c : s.toCharArray())
      sb.append(isVowel(c) ? vowels.get(i++) : c);

    return sb.toString();
  }

  private boolean isVowel(char c) {
    return "aeiouAEIOU".indexOf(c) != -1;
  }
}
