class Solution {
  public boolean isValid(String word) {
    return word.length() >= 3 && word.chars().allMatch(Character::isLetterOrDigit) &&
        word.chars().anyMatch(c -> isVowel((char) c)) &&
        word.chars().anyMatch(c -> isConsonant((char) c));
  }

  private boolean isVowel(char c) {
    return "aeiouAEIOU".indexOf(c) != -1;
  }

  private boolean isConsonant(char c) {
    return Character.isLetter(c) && !isVowel(c);
  }
}
