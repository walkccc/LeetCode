from dataclasses import dataclass


@dataclass
class Team:
  name: str
  rank: list[int]

  def __init__(self, name: str, teamSize: int):
    self.name = name
    self.rank = [0] * teamSize


class Solution:
  def rankTeams(self, votes: list[str]) -> str:
    teamSize = len(votes[0])
    teams = [Team(chr(ord('A') + i), teamSize) for i in range(26)]

    for vote in votes:
      for i in range(teamSize):
        teams[ord(vote[i]) - ord('A')].rank[i] += 1

    teams.sort(key=lambda x: (x.rank, -ord(x.name)), reverse=True)
    return ''.join(team.name for team in teams[:teamSize])
