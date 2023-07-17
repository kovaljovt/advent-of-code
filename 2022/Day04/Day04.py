def main():
    print(part1())
    print(part2())

def part1():
    with open("Day04.txt") as file:
        data = [i for i in file.read().split()]

    result = 0

    for entry in data:
        first, second = entry.split(",")
        first = [int(i) for i in first.split("-")]
        second = [int(i) for i in second.split("-")]
        if first[0] <= second[0] and first[1] >= second[1]:
            result += 1
        elif second[0] <= first[0] and second[1] >= first[1]:
            result += 1

    return result

def part2():
    with open("Day04.txt") as file:
        data = [i for i in file.read().split()]

    result = 0

    for entry in data:
        first, second = entry.split(",")
        first = [int(i) for i in first.split("-")]
        second = [int(i) for i in second.split("-")]
        if first[0] in range(second[0], second[1]+1) or\
                first[1] in range(second[0], second[1]+1):
            result += 1
        elif second[0] in range(first[0], first[1]+1) or\
                second[1] in range(first[0], first[1]+1):
            result += 1

    return result

main()