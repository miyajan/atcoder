import sys


def main():
    readline = sys.stdin.readline

    h1, h2, h3, w1, w2, w3 = map(int, readline().split())

    ans = 0
    for a1 in range(1, 31):
        if a1 + 1 >= h1:
            break
        if a1 + 1 >= w1:
            break
        for a2 in range(1, 31):
            if a1 + a2 >= h1:
                break
            if a2 + 1 >= w2:
                break
            for a4 in range(1, 31):
                if a4 + 1 >= h2:
                    break
                if a1 + a4 >= w1:
                    break
                for a5 in range(1, 31):
                    if a4 + a5 >= h2:
                        break
                    if a2 + a5 >= w2:
                        break
                    a3 = h1 - a1 - a2
                    a6 = h2 - a4 - a5
                    a7 = w1 - a1 - a4
                    a8 = w2 - a2 - a5
                    a9 = h3 - a7 - a8
                    if 1 <= a3 <= 30 and 1 <= a6 <= 30 and 1 <= a7 <= 30 and 1 <= a8 <= 30 and 1 <= a9 <= 30 and a3 + a6 + a9 == w3:
                        ans += 1

    print(ans)


if __name__ == '__main__':
    main()
