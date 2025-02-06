class Solution:
  def mostVisitedPattern(
      self,
      username: list[str],
      timestamp: list[int],
      website: list[str],
  ) -> list[str]:
    userToSites = collections.defaultdict(list)

    # Sort websites of each user by timestamp.
    for user, _, site in sorted(
            zip(username, timestamp, website),
            key=lambda x: x[1]):
      userToSites[user].append(site)

    # For each of three websites, count its frequency.
    patternCount = collections.Counter()

    for user, sites in userToSites.items():
      patternCount.update(Counter(set(itertools.combinations(sites, 3))))

    return max(sorted(patternCount), key=patternCount.get)
