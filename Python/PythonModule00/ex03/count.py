import sys

def text_analyzer(s=None):
	'''Takes a string and prints de number of uppercases, lowercases,
	punctuaition marks and spaces'''
	if not s:
		s = input("Enter a string\n")
	if isinstance(s, str):
		n_upper = 0
		n_lower = 0
		n_punct = 0
		n_space = 0
		for i in s:
			if i.isupper():
				n_upper += 1
			elif i.islower():
				n_lower += 1
			elif i.isspace():
				n_space += 1
			elif not i.isdigit():
				n_punct += 1
		print ("The text contains " + str(len(s)) + " character(s):")
		print("- " + str(n_upper) + " upper letter(s)")
		print("- " + str(n_lower) + " lower letter(s)")
		print("- " + str(n_punct) + " punctuation mark(s)")
		print("- " + str(n_space) + " space(s)")
	else:
		print("A string should have been given\n")
if __name__ == "__main__":
	if len(sys.argv) == 2:
		text_analyzer(sys.argv[1])
	elif len(sys.argv) > 2:
		print("Too many arguments")
