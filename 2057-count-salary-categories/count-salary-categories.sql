# Write your MySQL query statement below
-- SELECT 
-- CASE
--     WHEN income<20000 THEN 'Low Salary'
--     WHEN income>=20000 AND income<=50000 THEN 'Average Salary'
--     WHEN income>50000 THEN 'High Salary'
-- END AS category
-- FROM Accounts

SELECT "Low Salary" AS category,
SUM(IF(income<20000,1,0)) AS accounts_count FROM Accounts
UNION
SELECT "Average Salary" AS category,
SUM(IF(income>=20000 AND income<=50000,1,0)) AS accounts_count FROM Accounts
UNION
SELECT "High Salary" AS category,
SUM(IF(income>50000,1,0)) AS accounts_count FROM Accounts
