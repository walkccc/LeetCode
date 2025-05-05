class Solution {
 public:
  string intToRoman(int num) {
    const vector<string> M{"", "M", "MM", "MMM"};
    const vector<string> C{"",  "C",  "CC",  "CCC",  "CD",
                           "D", "DC", "DCC", "DCCC", "CM"};
    const vector<string> X{"",  "X",  "XX",  "XXX",  "XL",
                           "L", "LX", "LXX", "LXXX", "XC"};
    const vector<string> I{"",  "I",  "II",  "III",  "IV",
                           "V", "VI", "VII", "VIII", "IX"};
    return M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] +
           I[num % 10];
  }
};
