# TODO
import math


def count_letters(text):
    f = len(text)
    y = 0
    for i in range(f):
        if (text[i] >= "A" and text[i] <= "Z") or (text[i] >= "a" and text[i] <= "z"):
            y += 1
    return y


def count_words(text):
    f = len(text)
    y = 0
    for i in range(f):
        if text[i] == " ":
            y += 1
    return y + 1


def count_sentence(text):
    f = len(text)
    y = 0
    for i in range(f):
        if text[i] == "!" or text[i] == "." or text[i] == "?":
            y += 1
    return y


n = input("Text: ")
x = count_letters(n)
w = count_words(n)
c = count_sentence(n)
L = (x * 100 / w) + 0.5
S = (c * 100 / w) + 0.5
index = (0.0588 * L) - (0.296 * S) - 15.8
index1 = round(index)
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade", index1)
