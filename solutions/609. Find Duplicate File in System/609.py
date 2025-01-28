class Solution:
  def findDuplicate(self, paths: list[str]) -> list[list[str]]:
    contentToPathFiles = collections.defaultdict(list)

    for path in paths:
      words = path.split(' ')
      rootPath = words[0]  # "root/d1/d2/.../dm"
      for fileAndContent in words[1:]:  # "fn.txt(fn_content)"
        l = fileAndContent.find('(')
        r = fileAndContent.find(')')
        # "fn.txt"
        file = fileAndContent[:l]
        # "fn_content"
        content = fileAndContent[l + 1:r]
        # "root/d1/d2/.../dm/fn.txt"
        filePath = rootPath + '/' + file
        contentToPathFiles[content].append(filePath)

    return [filePath for filePath in contentToPathFiles.values() if len(filePath) > 1]
