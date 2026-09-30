# Write your MySQL query statement below
with temp_table
as (
    select 
        e.name as employee_name,
        d.name as department_name,
        e.salary,
        e.departmentId
    from Employee e
    join Department d
    on e.departmentId = d.id
) 

select department_name as Department,employee_name as Employee,salary as Salary from
(select temp_table.*,
dense_rank() over(
    partition by departmentId
    order by salary desc
) as rnk from temp_table
) t
where rnk<=3