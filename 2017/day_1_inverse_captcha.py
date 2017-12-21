def check_circular_next(digits):
    sum = 0
    size = len(digits)
    for i in xrange(size):
        if digits[i] == digits[(i + 1) % size]:
            sum += int(digits[i])
    return sum

def check_circular_halfway_around(digits):
    sum = 0
    size = len(digits)
    for i in xrange(size):
        if digits[i] == digits[(i + size / 2) % size]:
            sum += int(digits[i])
    return sum

def main():
    f = open('day_1_input.txt')
    digits = f.readline().rstrip()
    print check_circular_next(digits)
    print check_circular_halfway_around(digits)

if __name__ == '__main__':
    main()
