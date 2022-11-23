class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    const vector<string> morse{
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
    unordered_set<string> transformations;

    for (const string& word : words) {
      string transformation;
      for (const char c : word)
        transformation += morse[c - 'a'];
      transformations.insert(transformation);
    }

    return transformations.size();
  }
};
