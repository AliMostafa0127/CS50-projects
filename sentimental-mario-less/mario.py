
def get_height():
    while True:
        try:
            n = int(input("height: "))
            if n > 0 and n < 9:
                return n
        except ValueError:
            print("not intger")


height = get_height()
i = 1
for turn in range(height):
    for space in range(height - 1):
        print(" ", end="")
    for f in range(i):
        print("#", end="")
    i += 1
    height -= 1
    print()
