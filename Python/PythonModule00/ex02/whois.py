import sys

n = sys.argv
if len(n) == 2:
	msg = ''
	if n[1].isnumeric():
		if int(n[1]) == 0
			msg = "I'm Zero"
		if int(n[1])%2 == 0:
			msg = "I'm Even"
		else:
			msg = "I'm Odd"
	else:
		msg = "AssertionError: argument is not an integer"
	print (msg)
elif len(n) > 2:
	print("AssertionError: more than one argument are provided")
