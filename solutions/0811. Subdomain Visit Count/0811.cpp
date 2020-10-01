class Solution {
 public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    vector<string> ans;
    unordered_map<string, int> count;

    for (const string& cpdomain : cpdomains) {
      int space = cpdomain.find(' ');
      int num = stoi(cpdomain.substr(0, space));
      string domain = cpdomain.substr(space + 1);
      count[domain] += num;
      for (int i = 0; i < domain.length(); ++i)
        if (domain[i] == '.') count[domain.substr(i + 1)] += num;
    }

    for (const auto& [subdomain, freq] : count)
      ans.push_back(to_string(freq) + ' ' + subdomain);

    return ans;
  }
};