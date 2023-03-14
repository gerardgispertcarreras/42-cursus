import sys

def make_operations(A, B):
	print("Sum:\t\t" + str(A+B))
	print("Difference:\t" + str(A-B))
	print("Product:\t" + str(A*B))
	if B != 0:
		print("Quocient:\t" + str(A/B))
		print("Remainder:\t" + str(A%B))
	else:
		print("Quocient:\tERROR (division by zero)")
		print("Remainder:\tERROR (modulo by zero)")

arc = len(sys.argv)
arv = sys.argv

if arc == 3:
	if arv[1].isdigit() and arv[2].isdigit():
		A = int(sys.argv[1])
		B = int(sys.argv[2])
		make_operations(A, B)
	else:
		print("AssertionError: only integers")
elif arc == 1:
	print("Usage: python3 operations.py <number1> <number2>\nExample:\n\tpython operation.py 10 3")
else:
	print("Too many arguments")
