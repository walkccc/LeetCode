class Solution {
 public:
  int maximum69Number(int num) {
    string ans = to_string(num);

    for (char& c : ans)
      if (c == '6') {
        c = '9';
        break;
      }

    return stoi(ans);
  }
};
