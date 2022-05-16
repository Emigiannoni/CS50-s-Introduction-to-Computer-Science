from cs50 import get_string

def count_letters(text, l):

    l_counter = 0

    for i in text:

        if i.isalpha():

            l_counter += 1

    return l_counter


# counts any sequence of characters separated by spaces as a word
def count_words(text, l):

    w_counter = 1

    for i in text:

        if i.isspace():

            w_counter += 1

    return w_counter


# counts any occurrence of a period, exclamation point, or question mark as a indicator of the end of a sentence
def count_sentences(text, l):

    s_counter = 0

    for i in text:

        if i == '.' or i == '?' or i == '!':

            s_counter += 1

    return s_counter


# prompt user for imput

text = get_string("Text: ")

l = len(text)

# count the number of letters, words and sentences in the text

l_counter = count_letters(text, l)

w_counter = count_words(text, l)

s_counter = count_sentences(text, l)


# calculate the average number of letters per 100 words

L = (l_counter / w_counter) * 100

# calculate the average number of sentences per 100 words

S = (s_counter / w_counter) * 100

# calculate the Coleman-Liau index

index = (0.0588 * L) - (0.296 * S) - 15.8

# print the result

if index > 16:

    print("Grade 16+")

elif index < 1:

    print("Before Grade 1")

else:

    round_index = round(index)

    print(f"Grade {round_index}")

