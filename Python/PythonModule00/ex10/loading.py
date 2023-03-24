import time

def ft_progress(lst):
	for x in lst:
		yield x

if __name__ == '__main__':
	start = time.time()
	listy = range(1000)
	ret = 0
	for elem in ft_progress(listy):
		time.sleep(0.01)
		print("[{:3d}][{}]".format(100000/elem, str(int(100000/elem) * '=' + )), end = '\r')
	print(time.time() - start)