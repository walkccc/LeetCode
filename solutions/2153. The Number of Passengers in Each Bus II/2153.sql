WITH
  RECURSIVE BusesNeighbors AS (
    SELECT
      bus_id,
      arrival_time,
      capacity,
      IFNULL(LAG(arrival_time) OVER(
        ORDER BY arrival_time), 0
      ) AS prev_arrival_time
    FROM Buses
  ),
  BusesMetadata AS (
    SELECT
      BusesNeighbors.bus_id,
      BusesNeighbors.arrival_time,
      BusesNeighbors.capacity,
      BusesNeighbors.prev_arrival_time,
      COUNT(Passengers.passenger_id) AS waiting,
      ROW_NUMBER() OVER(
        ORDER BY BusesNeighbors.arrival_time
      ) AS `row_number`
    FROM BusesNeighbors
    LEFT JOIN Passengers
      ON (
        BusesNeighbors.prev_arrival_time < Passengers.arrival_time
        AND Passengers.arrival_time <= BusesNeighbors.arrival_time)
    GROUP BY 1, 2, 3
  ),
  Boarding AS (
    SELECT
      BusesMetadata.`row_number`,
      BusesMetadata.bus_id,
      LEAST(
        BusesMetadata.capacity,
        BusesMetadata.waiting
      ) AS boarded,
      GREATEST(
        0,
        BusesMetadata.waiting - BusesMetadata.capacity
      ) AS not_boarded
    FROM BusesMetadata
    WHERE `row_number` = 1
    UNION ALL
    SELECT
      BusesMetadata.`row_number`,
      BusesMetadata.bus_id,
      LEAST(
        BusesMetadata.capacity,
        Boarding.not_boarded + BusesMetadata.waiting
      ) AS boarded,
      GREATEST(
        0,
        Boarding.not_boarded + BusesMetadata.waiting - BusesMetadata.capacity
      ) AS not_boarded
    FROM BusesMetadata, Boarding
    WHERE BusesMetadata.`row_number` = Boarding.`row_number` + 1
  )
SELECT
  bus_id,
  boarded AS passengers_cnt
FROM Boarding
ORDER BY 1;
