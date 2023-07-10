
def factorial(num):
    if num <= 1:
        return num
    return num * factorial(num-1)
def solution(num):
    if num == '0':
        return 0
    cnt = 0
    for i in range(len(num)-1,-1,-1):
        if num[i] != '0':
            return cnt
        cnt += 1


if __name__ == '__main__':
    num = int(input())
    result = factorial(num)
    print(solution(str(result)))
