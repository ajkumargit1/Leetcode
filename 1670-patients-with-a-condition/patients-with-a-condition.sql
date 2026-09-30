# Write your MySQL query statement below
select *
from Patients
where concat(' ',conditions,' ') like "% DIAB1%"