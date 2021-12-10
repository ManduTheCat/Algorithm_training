def solution(rows, columns, connections, queries):
    node_count = rows + 1 * columns + 1
    adj_list = [[[]for _ in range(5)]for _ in range(columns + 2)]
    for c_list in connections:
        first = [c_list[0], c_list[1]]
        second =[c_list[2], c_list[3]]
        adj_list[first[0]][first[1]].append(second)
    print("queries : ",queries)
    for q_list in queries:
        r1 = q_list[0]
        c1 = q_list[1]
        r2 = q_list[2]
        c2 = q_list[3]
        print(q_list)
        print(r1,c1," ", r2, c2)
        if r2 < r1 and c2 < c1:
            for row_range in range(r1, r2 + 1):
                for col_range in range(c1,c2 + 1):
                    print(row_range, col_range)
        elif r1 < r2 and c1 < c2:
            for row_range in range(r2, r1+1):
                for col_range in range(c2, c1 + 1):
                    print(row_range, col_range)
        elif r2 < r1 and c1 < c2:
            for row_range in range(r1, r2+1):
                for col_range in range(c2, c1 + 1):
                    print(row_range, col_range)
        elif r1 < r2 and c2 < c1:
            for row_range in range(r2, r1+1):
                for col_range in range(c1, c2 + 1):
                    print(row_range, col_range)
        answer = []

    return answer
def main():
    con = [[1,1,2,1],[1,2,1,3],[1,3,2,3],[2,2,2,3],[2,2,3,2],[2,3,3,3],[3,2,3,3],[3,2,4,2],[4,1,4,2]]
    qur = [[2,2,3,1],[1,2,4,2]]
    solution(4, 3,con, qur)

if __name__ == "__main__":
    main()
