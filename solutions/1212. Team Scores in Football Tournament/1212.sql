WITH
  TwoWayMatches AS (
    SELECT
      host_team AS team_id,
      host_goals AS goals,
      guest_goals AS opponent_goals
    FROM Matches
    UNION ALL
    SELECT
      guest_team,
      guest_goals,
      host_goals
    FROM Matches
  )
SELECT
  Teams.team_id,
  Teams.team_name,
  SUM(
    CASE
      WHEN goals > opponent_goals THEN 3
      WHEN goals = opponent_goals THEN 1
      ELSE 0
    END
 ) AS num_points
FROM Teams
LEFT JOIN TwoWayMatches
  USING (team_id)
GROUP BY 1
ORDER BY num_points DESC, team_id;
