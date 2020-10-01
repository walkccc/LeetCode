class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> morse{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                         "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                         "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                         "...-", ".--",  "-..-", "-.--", "--.."};
    unordered_set<string> transformations;

    for (const string& word : words) {
      string transformation;
      for (char c : word) transformation += morse[c - 'a'];
      transformations.insert(transformation);
    }

    return transformations.size();
  }
};