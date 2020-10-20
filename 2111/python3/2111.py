#!/usr/bin/python3

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    weight = sum(arr)
    nalog = 0
    for i in arr:
        nalog += weight * i
        weight -= i
        nalog += weight * i
    print(nalog)

if __name__ == "__main__":
    main()
