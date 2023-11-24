WITH
  RankedWeather AS (
    SELECT
      *,
      RANK() OVER(
        PARTITION by city_id
        ORDER BY degree DESC, day
      ) AS `rank`
    FROM Weather
  )
SELECT city_id, day, degree
FROM RankedWeather
WHERE `rank` = 1;
