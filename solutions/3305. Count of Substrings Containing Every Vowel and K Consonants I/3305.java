class Solution {
  public int countOfSubstrings(String word, int k) {
    return substringsWithAtMost(word, k) - substringsWithAtMost(word, k - 1);
  }

  // Return the number of substrings containing every vowel with at most k
  // consonants.
  private int substringsWithAtMost(String word, int k) {
    if (k == -1)
      return 0;

    int res = 0;
    int vowels = 0;
    int uniqueVowels = 0;
    Map<Character, Integer> vowelLastSeen = new HashMap<>();

    for (int l = 0, r = 0; r < word.length(); ++r) {
      if (isVowel(word.charAt(r))) {
        ++vowels;
        if (!vowelLastSeen.containsKey(word.charAt(r)) || vowelLastSeen.get(word.charAt(r)) < l)
          ++uniqueVowels;
        vowelLastSeen.put(word.charAt(r), r);
      }
      while (r - l + 1 - vowels > k) {
        if (isVowel(word.charAt(l))) {
          --vowels;
          if (vowelLastSeen.get(word.charAt(l)) == l)
            --uniqueVowels;
        }
        ++l;
      }
      if (uniqueVowels == 5) {
        // Add substrings containing every vowel with at most k consonants to
        // the answer. They are
        // word[l..r], word[l + 1..r], ..., word[min(vowelLastSeen[vowel])..r]
        final int minVowelLastSeen = Arrays.asList('a', 'e', 'i', 'o', 'u')
                                         .stream()
                                         .mapToInt(vowel -> vowelLastSeen.get(vowel))
                                         .min()
                                         .getAsInt();
        res += minVowelLastSeen - l + 1;
      }
    }

    return res;
  }

  private boolean isVowel(char c) {
    return "aeiou".indexOf(c) != -1;
  }
}
