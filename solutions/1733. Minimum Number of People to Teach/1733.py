class Solution:
  def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
    languageSets = [set(languages) for languages in languages]
    needTeach = set()
    languageCount = collections.Counter()

    # Find friends that can't communicate.
    for u, v in friendships:
      if not languageSets[u - 1] & languageSets[v - 1]:
        needTeach.add(u - 1)
        needTeach.add(v - 1)

    # Find the most popular language.
    for u in needTeach:
      for language in languageSets[u]:
        languageCount[language] += 1

    # Teach the most popular language to people don't understand.
    return len(needTeach) - max(languageCount.values(), default=0)
