# TODO
from cs50 import get_float


def main():
    # Ask how many dollars the customer is owed
    dollars = get_dollars()
    cents = dollars * 100
    print(cents)
    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    print(quarters)
    cents = cents - quarters * 25
    print(cents)

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10
    print(f" {cents}")

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5
    print(cents)

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1
    print(cents)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


def get_dollars():
    dollars = get_float("Change owed:")
    while dollars < 0:
        dollars = get_float("Change owed:")
    return dollars


def calculate_quarters(n):
    quarters = n / 25
    return int(quarters)


def calculate_dimes(f):
    dimes = f / 10
    return int(dimes)


def calculate_nickels(j):
    nickels = j / 5
    return int(nickels)


def calculate_pennies(i):
    pennies = i / 1
    return int(pennies)


main()
