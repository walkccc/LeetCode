class TopVotedCandidate {
 public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times) : times(times) {
    unordered_map<int, int> count;  // {person: voted}
    int lead = -1;

    for (int i = 0; i < persons.size(); ++i) {
      if (++count[persons[i]] >= count[lead])
        lead = persons[i];
      timeToLead[times[i]] = lead;
    }
  }

  int q(int t) {
    auto it = --upper_bound(begin(times), end(times), t);
    return timeToLead[*it];
  }

 private:
  const vector<int> times;
  unordered_map<int, int> timeToLead;
};
