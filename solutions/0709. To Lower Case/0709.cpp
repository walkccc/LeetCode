class Solution {
 public:
  string toLowerCase(string str) {
    const int diff = 'A' - 'a';

    for (char& c : str)
      if (c >= 'A' && c <= 'Z')
        c -= diff;

    return str;
  }
};
