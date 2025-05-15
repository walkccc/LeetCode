struct Team {
  char name;
  vector<int> rank;
  Team(char name, int teamSize) : name(name), rank(teamSize) {}
};

class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    const int teamSize = votes[0].size();
    string ans;
    vector<Team> teams;

    for (int i = 0; i < 26; ++i)
      teams.push_back(Team('A' + i, teamSize));

    for (const string& vote : votes)
      for (int i = 0; i < teamSize; ++i)
        ++teams[vote[i] - 'A'].rank[i];

    ranges::sort(teams, ranges::greater{}, [](const Team& team) {
      return pair<vector<int>, char>{team.rank, -team.name};
    });

    for (int i = 0; i < teamSize; ++i)
      ans += teams[i].name;

    return ans;
  }
};
