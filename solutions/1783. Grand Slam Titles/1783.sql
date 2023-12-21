SELECT
  Players.player_id,
  Players.player_name,
  SUM(Players.player_id = Championships.Wimbledon) + SUM(Players.player_id = Championships.Fr_open) + SUM(Players.player_id = Championships.US_open) + SUM(Players.player_id = Championships.Au_open) AS grand_slams_count
FROM Players
INNER JOIN Championships
  ON (
    Players.player_id IN (
      Championships.Wimbledon,
      Championships.Fr_open,
      Championships.US_open,
      Championships.Au_open
    )
  )
GROUP BY 1;
