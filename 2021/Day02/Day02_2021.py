def main():
    print(part1())
    print(part2())

def part1():
    with open("Day02.txt") as file:
        data = []
        for i in file:
            data.append(i)

    depth = 0
    horizontal_position = 0
    result = 0

    for i in range(len(data)):
        parts = data[i].split()
        if parts[0] == 'forward':
            horizontal_position += int(parts[1])
        if parts[0] == 'up':
            depth -= int(parts[1])
        if parts[0] == 'down':
            depth += int(parts[1])

    result += depth * horizontal_position

    return result

def part2():
    with open("Day02.txt") as file:
        data = []
        for i in file:
            data.append(i)

    depth = 0
    horizontal_position = 0
    aim = 0
    result = 0

    for i in range(len(data)):
        parts = data[i].split()
        if parts[0] == 'forward':
            horizontal_position += int(parts[1])
            depth += aim * int(parts[1])
        if parts[0] == 'up':
            aim -= int(parts[1])
        if parts[0] == 'down':
            aim += int(parts[1])

    result += depth * horizontal_position

    return result

main()