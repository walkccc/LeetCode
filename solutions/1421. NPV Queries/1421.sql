SELECT
  Queries.id,
  Queries.year,
  IFNULL(NPV.npv, 0) AS npv
FROM Queries
LEFT JOIN NPV
  USING (id, year);
