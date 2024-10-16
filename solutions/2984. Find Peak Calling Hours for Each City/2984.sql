WITH
  CityHourCount AS (
    SELECT
      city,
      HOUR(call_time) AS call_hour,
      COUNT(*) AS number_of_calls
    FROM Calls
    GROUP BY 1, 2
  ),
  RankedCityHourCount AS (
    SELECT
      *,
      RANK() OVER(
        PARTITION BY city
        ORDER BY number_of_calls DESC
      ) AS `rank`
    FROM CityHourCount
  )
SELECT
  city,
  call_hour AS peak_calling_hour,
  number_of_calls
FROM RankedCityHourCount
WHERE `rank` = 1
ORDER BY 2 DESC, 1 DESC;
