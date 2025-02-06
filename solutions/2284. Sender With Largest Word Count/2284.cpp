class Solution {
 public:
  string largestWordCount(vector<string>& messages, vector<string>& senders) {
    const int n = messages.size();
    string ans;
    int maxWordsSent = 0;
    unordered_map<string, int> count;  // {sender, the number of words sent}

    for (int i = 0; i < n; ++i) {
      const string& message = messages[i];
      const string& sender = senders[i];
      const int wordsCount = ranges::count(message, ' ') + 1;
      count[sender] += wordsCount;
      const int numWordsSent = count[sender];
      if (numWordsSent > maxWordsSent) {
        ans = sender;
        maxWordsSent = numWordsSent;
      } else if (numWordsSent == maxWordsSent && sender > ans) {
        ans = sender;
      }
    }

    return ans;
  }
};
