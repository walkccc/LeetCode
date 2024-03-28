SELECT
  Teams.team_name,
  SUM(
    CASE
      WHEN Matches.home_team_id = Teams.team_id
      OR Matches.away_team_id = Teams.team_id THEN 1
      ELSE 0
    END
  ) AS matches_played,
  SUM(
    CASE
      WHEN Teams.team_id = Matches.home_team_id
      AND Matches.home_team_goals > Matches.away_team_goals THEN 3
      WHEN Teams.team_id = Matches.away_team_id
      AND Matches.home_team_goals < Matches.away_team_goals THEN 3
      WHEN Matches.home_team_goals = Matches.away_team_goals THEN 1
      ELSE 0
    END
  ) AS points,
  SUM(
    CASE
      WHEN Matches.home_team_id = Teams.team_id THEN Matches.home_team_goals
      ELSE Matches.away_team_goals
    END
  ) AS goal_for,
  SUM(
    CASE
      WHEN Matches.home_team_id = Teams.team_id THEN Matches.away_team_goals
      ELSE Matches.home_team_goals
    END
  ) AS goal_against,
  SUM(
    CASE
      WHEN Matches.home_team_id = Teams.team_id THEN Matches.home_team_goals - Matches.away_team_goals
      ELSE Matches.away_team_goals - Matches.home_team_goals
    END
  ) AS goal_diff
FROM Matches
INNER JOIN Teams
  ON (
    Matches.home_team_id = Teams.team_id
    OR Matches.away_team_id = Teams.team_id
  )
GROUP BY 1
ORDER BY points DESC, goal_diff DESC, team_name;
