import sys


def print_parentheses(current: str, count: int, level: int) -> None:
    if count == 0 and level == 0:
        print(current)
        return

    if count > 0:
        next_count = count - 1
        next_level = level + 1
        print_parentheses(current + "(", next_count, next_level)

    if level > 0:
        next_level = level - 1
        print_parentheses(current + ")", count, next_level)


def main():
    readline = sys.stdin.readline

    n = int(readline())
    if n % 2 != 0:
        return

    print_parentheses("", int(n / 2), 0)


if __name__ == '__main__':
    main()
