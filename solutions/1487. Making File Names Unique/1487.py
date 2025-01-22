class Solution:
  def getFolderNames(self, names: list[str]) -> list[str]:
    ans = []
    nameToSuffix = {}

    for name in names:
      if name in nameToSuffix:
        suffix = nameToSuffix[name] + 1
        newName = self._getName(name, suffix)
        while newName in nameToSuffix:
          suffix += 1
          newName = self._getName(name, suffix)
        nameToSuffix[name] = suffix
        nameToSuffix[newName] = 0
        ans.append(newName)
      else:
        nameToSuffix[name] = 0
        ans.append(name)

    return ans

  def _getName(self, name: str, suffix: int) -> str:
    return name + '(' + str(suffix) + ')'
