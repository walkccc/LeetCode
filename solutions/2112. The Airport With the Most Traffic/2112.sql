WITH
  AirportToCount AS (
    SELECT departure_airport AS airport_id, flights_count
    FROM Flights
    UNION ALL
    SELECT arrival_airport, flights_count
    FROM Flights
  ),
  RankedAirports AS (
    SELECT
      airport_id,
      RANK() OVER(ORDER BY SUM(flights_count) DESC) AS `rank`
    FROM AirportToCount
    GROUP BY 1
  )
SELECT airport_id
FROM RankedAirports
WHERE `rank` = 1;
