kata = (19, 42, 21)

l = len(kata)
if l > 0:
	s = ', '.join(str(x) for x in kata)
	print("The {len} numbers are: {numbers}".format(len=l, numbers = s))
else:
	print("There are no numbers in the tuple")