# 1 line: Output
print ('Hello, world!')

# 2 lines: Input, assignment
name = input('What is your name?\n')
print (f'Hi, {name}.')

# 3 lines: For loop, built-in enumerate function
friends = ['john', 'pat', 'gary', 'michael']
for i, name in enumerate(friends):
    print (f"iteration {i} is {name}")

# 4 lines: Fibonacci, tuple assignment
parents, babies = (1, 1)
while babies < 100:
    print (f'This generation has {babies} babies')
    parents, babies = (babies, parents + babies)

# 5 lines: Functions
def greet(name):
    print ('Hello', name)

greet('Jack')
greet('Jill')
greet('Bob')

# 7 lines: Dictionaries, generator expressions
prices = {'apple': 0.40, 'banana': 0.50}
my_purchase = {
    'apple': 1,
    'banana': 6}
grocery_bill = sum(prices[fruit] * my_purchase[fruit]
                   for fruit in my_purchase)
print (f'I owe the grocer ${grocery_bill:.2f}')
