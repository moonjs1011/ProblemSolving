
if __name__ == '__main__':
    # print(ord('a')-96)
    L = int(input())
    num = input()
    sum = 0
    for i in range(0,len(num)):
        sum += pow(31,i) * (ord(num[i]) - 96)
    print(sum %1234567891)




