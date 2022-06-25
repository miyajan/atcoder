import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())
    s = readline()[:-1]
    w = list(map(int, readline().split()))

    weight_type = {}
    current = 0
    for i in range(n):
        if s[i] == '1':
            current += 1
        if w[i] not in weight_type:
            weight_type[w[i]] = 0
        if s[i] == '0':
            weight_type[w[i]] += 1
        else:
            weight_type[w[i]] -= 1

    keys = weight_type.keys()
    sorted_keys = sorted(keys)

    ma = current
    for i in range(len(sorted_keys)):
        current += weight_type[sorted_keys[i]]
        if current > ma:
            ma = current

    print(ma)


if __name__ == '__main__':
    main()
