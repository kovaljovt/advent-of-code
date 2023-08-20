from string import ascii_letters

def main():
    print(part1())
    print(part2())

def part1():
    with open("Day03.txt") as file:
        data = [i for i in file.read().strip().split()]

    result = 0

    for rucksack in data:
        half = len(rucksack) // 2
        left = rucksack[:half]
        right = rucksack[half:]
        for priority, character in enumerate(ascii_letters):
            if character in left and character in right:
                result += priority + 1

    return result

def part2():
    with open("Day03.txt") as file:
        data = [i for i in file.read().strip().split()]
    result = 0
    iterator = 3
    for i in range(0, len(data), 3):
        rucksacks = data[i:iterator]
        iterator += 3
        for priority, character in enumerate(ascii_letters):
            if character in rucksacks[0] and character in rucksacks[1] and character in rucksacks[2]:
                result += priority + 1
    return result

main()