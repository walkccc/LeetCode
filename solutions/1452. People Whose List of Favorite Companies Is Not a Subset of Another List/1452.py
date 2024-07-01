class Solution:
  def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
    ans = []
    n = len(favoriteCompanies)
    companies = [set(comp) for comp in favoriteCompanies]

    for i in range(n):
      find = False
      for j in range(n):
        if i == j:
          continue
        if companies[i].issubset(companies[j]):
          find = True
          break
      if not find:
        ans.append(i)

    return ans
