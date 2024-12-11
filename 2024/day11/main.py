from functools import cache

with open("input.txt", "r") as f:
    data = f.read().split()


@cache
def recursive_count(num: str, iter: int) -> int:
    if iter == 0:
        return 1
    if num == "0":
        return recursive_count("1", iter - 1)
    if len(num) % 2 == 0:
        n = len(num)
        left = recursive_count(num[: n // 2], iter - 1)
        right = recursive_count(num[n // 2 :].lstrip("0") or "0", iter - 1)
        return left + right

    return recursive_count(str(int(num) * 2024), iter - 1)


def main():
    with open("input.txt") as f:
        data = f.read().split()

    print(f"Part 1: {sum(recursive_count(num, 25) for num in data)}")
    print(f"Part 2: {sum(recursive_count(num, 75) for num in data)}")


if __name__ == "__main__":
    main()
