import random

if __name__ == '__main__':
	print("This is an interactive guessing game!\n"
		  "You have to enter a number between 1 and 99 to find out the secret number.")
	x = str(random.randint(1, 99))
	steps = 1
	y = input("What's your guess between 1 and 99?\n")
	while y != x:
		if not y.isdigit():
			print("That's not a number")
		else:
			if y < x:
				print("Too low!")
			else:
				print("Too high!")
			steps += 1
		y = input("What's your guess between 1 and 99?\n")
	print("Congratulations, you've got it!\n"
		  "You won in {} attempts!".format(steps))
	
