WITH
  TeamPoints AS (
    SELECT
      season_id,
      team_id,
      team_name,
      wins * 3 + draws AS points,
      goals_for - goals_against AS goal_difference
    FROM SeasonStats
  ),
  RankedTeams AS (
    SELECT
      *,
      RANK() OVER(
        PARTITION BY season_id
        ORDER BY points DESC, goal_difference DESC, team_name
      ) AS position
    FROM TeamPoints
  )
SELECT * FROM RankedTeams
ORDER BY season_id, position, team_name;
