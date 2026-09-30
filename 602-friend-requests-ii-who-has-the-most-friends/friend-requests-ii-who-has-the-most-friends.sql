# Write your MySQL query statement below
with temp_table
as (
    select requester_id as id from RequestAccepted
    union all
    select accepter_id as id from RequestAccepted
)
select id,count(*) as num
from temp_table
group by id
order by count(*) desc
limit 1;