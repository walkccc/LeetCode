class Solution {
 public:
  bool doesAliceWin(string s) {
    // Let k be the number of vowels in s.
    // 1. If k == 0, Bob wins since Alice has no vowels to pick.
    // 2. If k % 2 == 1, Alice wins since Alice can pick the entire string.
    // 3. If k % 2 == 0, Alice wins since Alice can pick (k - 1) vowels,
    // then Bob will either pick a substring containing 0 vowels, resulting in
    // Alice picking the remaining entire string, or Bob couldn't pick at all
    // (the last vowel).
    return ranges::any_of(s, [=](char c) { return isVowel(c); });
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiou";
    return kVowels.find(c) != string_view::npos;
  }
};
