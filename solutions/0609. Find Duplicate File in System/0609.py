class Solution:
  def findDuplicate(self, paths: List[str]) -> List[List[str]]:
    files = {}

    for path in paths:
      words = path.split(' ')
      root = words[0]
      for i in range(1, len(words)):
        s = words[i]
        filePath = root + '/' + s[0:s.find('(')]
        fileContent = s[s.find('(') + 1:s.find(')')]
        if fileContent not in files:
          files[fileContent] = []
        files[fileContent].append(filePath)

    return [filePath for filePath in files.values() if len(filePath) > 1]
