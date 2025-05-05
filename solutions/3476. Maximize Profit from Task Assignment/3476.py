class Solution:
  def maxProfit(self, workers: list[int], tasks: list[list[int]]) -> int:
    totalProfit = 0
    skillToProfits = collections.defaultdict(list)

    for skill, profit in tasks:
      skillToProfits[skill].append(profit)

    for skill in skillToProfits:
      skillToProfits[skill].sort(reverse=True)

    for workerSkill in workers:
      if workerSkill in skillToProfits and skillToProfits[workerSkill]:
        profit = skillToProfits[workerSkill][0]
        skillToProfits[workerSkill].pop(0)
        totalProfit += profit

    return totalProfit + max(max(profits, default=0)
                             for profits in skillToProfits.values())
