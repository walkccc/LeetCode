WITH
  RECURSIVE BusesNeighbors AS (
    SELECT
      bus_id,
      arrival_time,
      IFNULL(LAG(arrival_time) OVER(
        ORDER BY arrival_time), 0
      ) AS prev_arrival_time
    FROM Buses
  )
SELECT
  BusesNeighbors.bus_id,
  COUNT(Passengers.passenger_id) AS passengers_cnt
FROM BusesNeighbors
LEFT JOIN Passengers
  ON (
    BusesNeighbors.prev_arrival_time < Passengers.arrival_time
    AND Passengers.arrival_time <= BusesNeighbors.arrival_time)
GROUP BY 1
ORDER BY 1;
