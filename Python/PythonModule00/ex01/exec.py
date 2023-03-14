import sys

def reverse(s):
	str = ' '
	for i in s:
		if i.isupper():
			str = i.lower() + str
		else:
			str = i.upper() + str
	return str

if len(sys.argv) > 1:
	s = sys.argv[1]
	for i in sys.argv[2:]:
		s += ' ' + i
	print(reverse(s))