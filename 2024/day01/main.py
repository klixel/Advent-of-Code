from collections import Counter
from typing import List


def part1(left_column: List[int], right_column: List[int]) -> int:
    return sum(abs(a - b) for a, b in zip(sorted(left_column), sorted(right_column)))


def part2(left_column: List[int], right_column: List[int]) -> int:
    right_counter = Counter(right_column)
    return sum(a * right_counter[a] for a in left_column)


def main():
    with open("input.txt") as f:
        left_column, right_column = zip(*[map(int, line.split()) for line in f])

    with open("output.txt", "w") as f:
        print(f'Part 1: {part1(left_column, right_column)}', file=f)
        print(f'Part 2: {part2(left_column, right_column)}', file=f)


if __name__ == "__main__":
    main()
