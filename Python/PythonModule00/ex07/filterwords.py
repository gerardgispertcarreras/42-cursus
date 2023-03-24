import sys
import string

def filter_words(s, n):
	l = s.split()
	l2 = []
	for x in l:
		for y in string.punctuation:
			x = x.replace(y, '')
		if len(x) > n:
			l2 += [x]
	print(l2)

if __name__ == '__main__':
	arv = sys.argv
	arc = len(arv)
	if arc == 3:
		if isinstance(arv[1], str) and arv[2].isdigit():
			filter_words(arv[1], int(arv[2]))
		else:
			print('ERROR')
	else:
		print('ERROR')