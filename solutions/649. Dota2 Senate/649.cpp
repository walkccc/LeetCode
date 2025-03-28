class Solution {
 public:
  string predictPartyVictory(string senate) {
    const int n = senate.length();
    queue<int> qR;
    queue<int> qD;

    for (int i = 0; i < n; ++i)
      if (senate[i] == 'R')
        qR.push(i);
      else
        qD.push(i);

    while (!qR.empty() && !qD.empty()) {
      const int indexR = qR.front();
      qR.pop();
      const int indexD = qD.front();
      qD.pop();
      if (indexR < indexD)
        qR.push(indexR + n);
      else
        qD.push(indexD + n);
    }

    return qR.empty() ? "Dire" : "Radiant";
  }
};
