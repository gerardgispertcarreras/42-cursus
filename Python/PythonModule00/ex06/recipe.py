cookbook = {}

def print_options():
	print('List of available option:\n'
		  '\t1: Add a recipe\n'
		  '\t2: Delete a recipe\n'
		  '\t3: Print a recipe\n'
		  '\t4: Print the cookbook\n'
		  '\t5: Quit\n')

def add_recipe():
	recipe = input('Enter a name:')
	if recipe not in cookbook:
		ingredients = []
		x = input('Enter ingredients:')
		while x:
			ingredients += x
			x = input()
		meal = input('Enter a meal type:')
		prep_time = input('Enter a preparation time:')
		cookbook[recipe] =  {'ingredients' : ingredients, 'meal' : meal, 'prep_time': prep_time}
	else:
		print('The recipe you want to add is already in the cookbook.')

def delete_recipe():
	recipe = input('Which recipe do you want to delete?')
	if recipe in cookbook:
		del cookbook[recipe]
	else:
		print('The recipe you want to delete is not in the cookbook.')

def print_cookbook():
	print(*cookbook, sep = '\n')

def print_recipe():
	recipe = input("Please enter a recipe name to get its details:\n")
	if recipe in cookbook:
		print("Recipe for {}:\n\tIngredients list: {}\n\tTo be eaten for {}.\n\tTakes {} minutes of cooking"\
		.format(recipe, cookbook[recipe]['ingredients'], cookbook[recipe]['meal'], cookbook[recipe]['prep_time']))
	else:
		print('The recipe you want to see is not in the cookbook')

if __name__ == '__main__':
	options_dic = {
		'1' : add_recipe,
		'2' : delete_recipe,
		'3' : print_recipe,
		'4' : print_cookbook
	}
	print('Welcome to the Python Cookbook !')
	print_options()
	option = input('Please select an option:\n')
	while option != '5':
		if option in options_dic:
			options_dic[option]()
		else:
			print('Sorry this option does not exist.')
		option = input('Please select an option:\n')
