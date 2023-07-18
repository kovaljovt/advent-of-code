def main():
    print(part1())
    print(part2())

def part1():
    with open("Day03.txt") as file:
        data = [x for x in file.read().strip().split('\n')]

    cols = len(data[0])

    gamma = ''
    epsilon = ''

    for i in range(cols):
        zeros = 0
        ones = 0
        for j in range(len(data)):
            if data[j][i] == '0':
                zeros += 1
            elif data[j][i] == '1':
                ones += 1

        if zeros > ones:
            gamma += '0'
            epsilon += '1'
        else:
            gamma += '1'
            epsilon += '0'

    result = int(gamma, 2) * int(epsilon, 2)

    return result

def part2():
    with open("Day03.txt") as file:
        data = [x for x in file.read().strip().split('\n')]

main()