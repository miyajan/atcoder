import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())
    neighbours = {}
    for i in range(1, n + 1):
        neighbours[i] = []

    for i in range(n - 1):
        ai, bi = map(int, readline().split())
        neighbours[ai].append(bi)
        neighbours[bi].append(ai)

    currents = [1]
    passed = {1}
    while True:
        nexts = []
        for i in currents:
            for j in neighbours[i]:
                if j not in passed:
                    nexts.append(j)
                    passed.add(j)
        if len(nexts) == 0:
            break
        currents = nexts

    currents = [currents[0]]
    passed = {currents[0]}
    depth = 0
    while True:
        nexts = []
        for i in currents:
            for j in neighbours[i]:
                if j not in passed:
                    nexts.append(j)
                    passed.add(j)
        if len(nexts) == 0:
            break
        currents = nexts
        depth += 1

    print(depth + 1)


if __name__ == '__main__':
    main()
