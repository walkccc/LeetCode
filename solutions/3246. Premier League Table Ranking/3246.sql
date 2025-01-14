WITH
  TeamPoints AS (
    SELECT team_id, team_name, wins * 3 + draws AS points
    FROM TeamStats
  ),
  RankedTeams AS (
    SELECT *, RANK() OVER(ORDER BY points DESC) AS position
    FROM TeamPoints
  )
SELECT team_id, team_name, points, position
FROM RankedTeams
ORDER BY points DESC, team_name;
