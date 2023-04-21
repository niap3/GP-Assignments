import random
import re
import string

file_obj = open("wordsList.txt", "r")
file_data = file_obj.read()
lines = file_data.splitlines()
file_obj.close()

# vowelCounting fucntion, returns number of vowels


def vowelCounter(string):
    regex = re.findall("a|e|i|o|u", string)
    count = len(regex)
    return (count)


print("Start with 'A' and input a word. (The word with the least number vowels wins a round!)")
first = 'a'
listOfRepeat = []
user = 0
cpu = 0
while (1):
    answer = input("Enter answer here: ")

    # check if it's repeated
    if answer in listOfRepeat:
        print("You already answered with that word, Please come up with something else...")
        print("Start again!")
        exit(0)

    # making user input into smallcase
    answer.lower

    # checking if the answer starts from the "first" letter
    if answer[0] == first:
        pass
    else:
        print("Invalid answer! You started with another letter! You lose, start again!")
        exit(0)

    # checking if answer is in word list, if its a valid word ie
    if answer in lines:
        res = []

        # lines is  the list where all the words are
        # make list res of all the words that start with "first" letter
        for i in lines:
            if (i.startswith(first)):
                res.append(i)

        # printing a random value from res list, this is the computer's response
        computerResponse = random.choice(res)
        print("Computer's response: ", computerResponse)

        # printing vowel count
        vowelCounter(answer)
        vowelCounter(computerResponse)
        print("\nYour response had ", vowelCounter(
            answer), " vowels and the Computer's response had ", vowelCounter(computerResponse), " vowels so,")

        # comparing the vowelCounts of both the responses, the one with the maximum vowels win
        if vowelCounter(answer) >= vowelCounter(computerResponse):
            if vowelCounter(answer) > vowelCounter(computerResponse):
                user += 1
                print("You win!\nScore: ", user, "-", cpu,
                      "\nNow continue with: ", answer[-1])
                first = answer[-1]

            else:
                user += 1
                cpu += 1
                print("Number of vowels are the same!\nYou both win!!",
                      "\nScore: ", user, "-", cpu, "\nNow continue with: ", answer[-1])
                first = answer[-1]

        else:
            cpu += 1
            print("Computer wins!\nScore [You - Computer]: ", user,
                  "-", cpu, "\nNow continue with: ", computerResponse[-1])
            first = computerResponse[-1]

        # adding the answer to the repeat list
        listOfRepeat.append(answer)

        # round ends
        yesNo = input("Do you want to resume? Press N if no: ")
        if yesNo == 'n' or yesNo == 'N':
            exit(0)
    else:
        print("Invalid answer! You lose! Start again!")
        exit(0)
