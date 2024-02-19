def knapsack(subjects, total_time):
    employees= dict(
        input('Enter value and study time separated by space: ').split()
        for _ in range(subjects))
    score = 0
    employees = dict(sorted(employees.items(), key=lambda item: int(item[0]) / int(item[1]), reverse=True))
    for x in employees.keys():
        if total_time == 0:
            break
        if int(employees[x]) <= total_time:
            score += int(x)
            total_time -= int(employees[x])
        else:
            score += int(x) * (total_time / int(employees[x]))
            total_time = 0
    return score


subjects = int(input("Enter the Number of Subjects: "))
total_time = int(input("Enter the Total Time: "))
score = knapsack(subjects, total_time)
print(score)
