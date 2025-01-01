class Solution:
  def countOfAtoms(self, formula: str) -> str:
    def parse() -> dict:
      ans = collections.defaultdict(int)

      nonlocal i
      while i < n:
        if formula[i] == '(':
          i += 1
          for elem, freq in parse().items():
            ans[elem] += freq
        elif formula[i] == ')':
          i += 1
          numStart = i
          while i < n and formula[i].isdigit():
            i += 1
          factor = int(formula[numStart:i])
          for elem, freq in ans.items():
            ans[elem] *= factor
          return ans
        elif formula[i].isupper():
          elemStart = i
          i += 1
          while i < n and formula[i].islower():
            i += 1
          elem = formula[elemStart:i]
          numStart = i
          while i < n and formula[i].isdigit():
            i += 1
          num = 1 if i == numStart else int(
              formula[numStart:i])
          ans[elem] += num

      return ans

    n = len(formula)

    ans = ""
    i = 0
    count = parse()

    for elem in sorted(count.keys()):
      ans += elem
      if count[elem] > 1:
        ans += str(count[elem])

    return ans
