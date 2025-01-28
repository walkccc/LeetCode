WITH
  TeamPoints AS (
    SELECT team_id, team_name, wins * 3 + draws AS points
    FROM TeamStats
  ),
  RankedTeams AS (
    SELECT *, RANK() OVER(ORDER BY points DESC) AS position
    FROM TeamPoints
  ),
  Tiers AS (
    SELECT
      CEIL(COUNT(*) * 0.33) AS tier1_bound,
      CEIL(COUNT(*) * 0.67) AS tier2_bound
    FROM RankedTeams
  )
SELECT
  RankedTeams.team_name,
  RankedTeams.points,
  RankedTeams.position,
  CASE
    WHEN RankedTeams.position <= Tiers.tier1_bound THEN 'Tier 1'
    WHEN RankedTeams.position <= Tiers.tier2_bound THEN 'Tier 2'
    ELSE 'Tier 3'
  END AS tier
FROM RankedTeams
CROSS JOIN Tiers
ORDER BY points DESC, team_name;
