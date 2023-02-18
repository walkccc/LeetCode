class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int gcd_len = gcd(len1, len2);
        string sub = str1.substr(0, gcd_len);
        if (str1 + str2 == str2 + str1 && str1.substr(0, gcd_len) == str2.substr(0, gcd_len)) {
            return sub;
        } else {
            return "";
        }
    }
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
