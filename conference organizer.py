def schedule_talks(talks):
    sorted_talks = sorted(talks, key=lambda x: x[1])
    end_time = float('-inf')
    count=0
    for talk in sorted_talks:
        start, end = talk
        if start >= end_time:
            count += 1
            end_time = end
    return count


talks_list = [(1, 4), (2, 6), (3, 7), (4, 8), (8, 9)]
max_talks = schedule_talks(talks_list)
print(f"Maximum non-overlapping talks: {max_talks}")
