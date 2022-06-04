import sys


def main():
    readline = sys.stdin.readline

    n, k = map(int, readline().split())

    a = list(map(int, readline().split()))
    num_pos_dict = {}
    for i in range(n):
        if a[i] in num_pos_dict:
            num_pos_dict[a[i]].append(i)
        else:
            num_pos_dict[a[i]] = [i]
    b = sorted(a)
    ans = "Yes"
    for i in range(n):
        ans = "No"
        num = b[i]
        for j, pos in enumerate(num_pos_dict[num]):
            if abs(pos - i) % k == 0:
                ans = "Yes"
                num_pos_dict[b[i]] = num_pos_dict[b[i]][0:j] + num_pos_dict[b[i]][j + 1:]
                break
        if ans == "No":
            break

    print(ans)


if __name__ == '__main__':
    main()
