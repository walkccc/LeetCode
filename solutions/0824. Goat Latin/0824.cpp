class Solution {
 public:
  string toGoatLatin(string S) {
    string ans;
    const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                     'A', 'E', 'I', 'O', 'U'};
    istringstream iss(S);
    string word;
    int i = 1;

    while (iss >> word) {
      if (i > 1)
        ans += ' ';
      if (vowels.count(word[0]))
        ans += word;
      else
        ans += word.substr(1) + word[0];
      ans += "ma" + string(i++, 'a');
    }

    return ans;
  }
};
