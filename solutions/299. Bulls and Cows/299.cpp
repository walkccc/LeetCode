class Solution {
 public:
  string getHint(string secret, string guess) {
    int A = 0;
    int B = 0;
    vector<int> count1(10);
    vector<int> count2(10);

    for (int i = 0; i < secret.length(); ++i)
      if (secret[i] == guess[i])
        ++A;
      else {
        ++count1[secret[i] - '0'];
        ++count2[guess[i] - '0'];
      }

    for (int i = 0; i < 10; ++i)
      B += min(count1[i], count2[i]);

    return to_string(A) + "A" + to_string(B) + "B";
  }
};
