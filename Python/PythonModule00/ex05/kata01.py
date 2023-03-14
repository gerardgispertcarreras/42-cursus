kata = {
'Python': 'Guido van Rossum',
'Ruby': 'Yukihiro Matsumoto',
'PHP': 'Rasmus Lerdorf',
'Gerard Gispert Carreras': 'God of Gods'
}

l = len(kata)
if l > 0:
	for key in kata:
		print(key + " was created by " + kata[key])
else:
	print("There are no entries in the dictionary")