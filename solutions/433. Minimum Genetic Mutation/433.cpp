class Solution {
 public:
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> bankSet{bank.begin(), bank.end()};
    if (!bankSet.contains(endGene))
      return -1;

    constexpr char kGenes[] = "ACGT";
    queue<string> q{{startGene}};

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        string word = q.front();
        q.pop();
        for (int j = 0; j < word.length(); ++j) {
          const char cache = word[j];
          for (const char c : kGenes) {
            word[j] = c;
            if (word == endGene)
              return step;
            if (bankSet.contains(word)) {
              bankSet.erase(word);
              q.push(word);
            }
          }
          word[j] = cache;
        }
      }

    return -1;
  }
};
