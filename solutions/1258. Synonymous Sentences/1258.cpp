class Solution {
 public:
  vector<string> generateSentences(vector<vector<string>>& synonyms,
                                   string text) {
    set<string> ans;
    unordered_map<string, vector<string>> graph;
    queue<string> q{{text}};

    for (const vector<string>& synonym : synonyms) {
      const string& s = synonym[0];
      const string& t = synonym[1];
      graph[s].push_back(t);
      graph[t].push_back(s);
    }

    while (!q.empty()) {
      const string u = q.front();
      q.pop();
      ans.insert(u);
      vector<string> words = split(u);
      for (string& word : words) {
        const auto it = graph.find(word);
        if (it == graph.cend())
          continue;
        for (const string& synonym : it->second) {
          // Replace words[i] with its synonym.
          word = synonym;
          const string newText = join(words, ' ');
          if (!ans.count(newText))
            q.push(newText);
        }
      }
    }

    return {ans.begin(), ans.end()};
  }

 private:
  vector<string> split(const string& s) {
    vector<string> words;
    istringstream iss(s);
    for (string token; iss >> token;)
      words.push_back(token);
    return words;
  }

  string join(const vector<string>& words, char c) {
    string joined;
    for (int i = 0; i < words.size(); ++i) {
      joined += words[i];
      if (i != words.size() - 1)
        joined += c;
    }
    return joined;
  }
};
