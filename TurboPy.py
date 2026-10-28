# Python Keywords & Data Types Demonstration

from math import sqrt

# -----------------------------
# Numeric Data Types
# -----------------------------
integer_num = 42                # int
float_num = 3.14                # float
complex_num = 2 + 3j            # complex

# -----------------------------
# Sequence Data Types
# -----------------------------
text = "Hello Python"           # str
numbers = [1, 2, 3]            # list
coordinates = (10, 20)         # tuple
byte_data = b"ABC"             # bytes
byte_array = bytearray(b"XYZ") # bytearray
buffer = memoryview(byte_data) # memoryview

# -----------------------------
# Set Types
# -----------------------------
unique_values = {1, 2, 3}      # set
immutable_set = frozenset({4, 5, 6})  # frozenset

# -----------------------------
# Mapping Type
# -----------------------------
person = {"name": "Alice", "age": 30}  # dict

# -----------------------------
# Boolean & None
# -----------------------------
is_active = True               # bool
nothing = None                 # NoneType

# -----------------------------
# Global Variable Example
# -----------------------------
global_var = "I am global"

# -----------------------------
# Class Definition
# -----------------------------
class Person:
    species = "Human"

    def __init__(self, name):
        self.name = name

    def greet(self):
        return f"Hello, I am {self.name}"

# -----------------------------
# Function with Keywords
# -----------------------------
def calculate(value):
    global global_var

    try:
        if value < 0:
            raise ValueError("Negative value not allowed")

        result = sqrt(value)

    except ValueError as err:
        print(f"Error: {err}")
        result = None

    else:
        print("Calculation successful")

    finally:
        print("Finished calculation")

    return result

# -----------------------------
# Generator Using yield
# -----------------------------
def counter():
    for i in range(3):
        yield i

# -----------------------------
# Lambda Function
# -----------------------------
square = lambda x: x * x

# -----------------------------
# Async & Await
# -----------------------------
import asyncio

async def async_task():
    await asyncio.sleep(0.1)
    return "Async Complete"

# -----------------------------
# Context Manager (with)
# -----------------------------
with open("sample.txt", "w") as file:
    file.write("Python keywords demo")

# -----------------------------
# Loop Keywords
# -----------------------------
for item in numbers:
    if item == 2:
        continue
    elif item == 3:
        break
    print(item)

# -----------------------------
# While Loop
# -----------------------------
count = 0
while count < 2:
    count += 1

# -----------------------------
# Assertions
# -----------------------------
assert integer_num == 42

# -----------------------------
# Del Keyword
# -----------------------------
temp = [1, 2, 3]
del temp

# -----------------------------
# Import Keyword Example
# -----------------------------
import math

# -----------------------------
# Match Case (Python 3.10+)
# -----------------------------
value = 2

match value:
    case 1:
        print("One")
    case 2:
        print("Two")
    case _:
        print("Other")

# -----------------------------
# Using Generator
# -----------------------------
for num in counter():
    print(num)

# -----------------------------
# Object Creation
# -----------------------------
p = Person("John")
print(p.greet())

# -----------------------------
# Using Function
# -----------------------------
print(calculate(16))

# -----------------------------
# Lambda Usage
# -----------------------------
print(square(5))

# -----------------------------
# Async Execution
# -----------------------------
asyncio.run(async_task())

# -----------------------------
# Membership Operators
# -----------------------------
print("Alice" if "name" in person else "Unknown")

# -----------------------------
# Identity Operators
# -----------------------------
another_none = None

if nothing is another_none:
    print("Same object")

if numbers is not coordinates:
    print("Different objects")
