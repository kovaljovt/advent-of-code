def main():
    print(part1())
    print(part2())

def update(position, direction):
    if direction == "^":
        return position[0], position[1] + 1
    elif direction == "<":
        return position[0] - 1, position[1]
    elif direction == ">":
        return position[0] + 1, position[1]
    elif direction == "v":
        return position[0], position[1] - 1

def part1():
    with open("Day03.txt") as file:
        data = [i for i in file.read().strip()]

    visited = set()
    visited.add((0, 0))
    position = (0, 0)

    for direction in data:
        position = update(position, direction)
        visited.add(position)

    result = len(visited)

    return result

def part2():
    with open("Day03.txt") as file:
        data = [i for i in file.read().strip()]

    visited = set()
    visited.add((0, 0))
    santa = (0, 0)
    robo_santa = (0, 0)

    for i, direction in enumerate(data):
        if i % 2 == 0:
            robo_santa = update(robo_santa, direction)
            visited.add(robo_santa)
        else:
            santa = update(santa, direction)
            visited.add(santa)

    result = len(visited)

    return result

main()