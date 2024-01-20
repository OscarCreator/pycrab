from pycrab import Point, Crab

# TODO test library

a = Point(1, 2)
b = Point(2, 3)
print(dir(a))
print(type(a))
print(a.x)
a.x = 5

print(a.diff(b))

crab = Crab(a, b)

print(crab.position)
