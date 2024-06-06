SELECT
  Home.team_name AS home_team,
  Away.team_name AS away_team
FROM Teams AS Home
INNER JOIN Teams AS Away
WHERE Home.team_name != Away.team_name;
