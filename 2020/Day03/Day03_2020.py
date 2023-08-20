def main():
    with open("Day03.txt", "r") as file:
        inarr = [line.strip() for line in file]

    print(part1(inarr))
    print(part2(inarr))


def find_trees(inarr, y, x):
    curry = 0
    currx = 0
    count = 0

    while curry < len(inarr):
        if inarr[curry][currx % len(inarr[0])] == '#':
            count += 1
        curry += y
        currx += x

    return count


def part1(inarr):
    return find_trees(inarr, 1, 3)


def part2(inarr):
    variations = [(1, 1), (1, 3), (1, 5), (1, 7), (2, 1)]
    treeprod = 1

    for i in variations:
        treeprod *= find_trees(inarr, i[0], i[1])

    return treeprod


main()
