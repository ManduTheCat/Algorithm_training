import sys


def solution():
    balls  = [1, 0, 0]
    input_time = int(input())
    for i in range(input_time):
        change_command= list(map(int, sys.stdin.readline().split(" ")))
        balls[change_command[0] - 1], balls[change_command[1] - 1] = balls[change_command[1] - 1], balls[change_command[0] - 1]
    for i, v in enumerate(balls):
        if v == 1:
            print(i + 1)
def main():
    solution()
if __name__ == "__main__":
    main()
