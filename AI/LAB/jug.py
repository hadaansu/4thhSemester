j1 = 0
j2 = 0

x = int(input("Enter the capacity of jug 1: "))
y = int(input("Enter the capacity of jug 2: "))
goal_j1 = int(input("Enter the goal state for jug 1: "))
goal_j2 = int(input("Enter the goal state for jug 2: "))

print("Initial state = (0,0)")
print("Capacities = ({}, {})".format(x, y))
print("Goal state = ({}, {})".format(goal_j1, goal_j2))

while j1 != goal_j1 or j2 != goal_j2:
    r = int(input("Enter the rule: "))
    if r == 1:
        j1 = x
    elif r == 2:
        j2 = y
    elif r == 3:
        j1 = 0
    elif r == 4:
        j2 = 0
    elif r == 5:
        t = min(j1, y - j2)
        j1 -= t
        j2 += t
    elif r == 6:
        t = min(j2, x - j1)
        j1 += t
        j2 -= t
    elif r == 7:
        j2 = min(j1 + j2, y)
        j1 = max(j1 + j2 - y, 0)
    elif r == 8:
        j1 = min(j1 + j2, x)
        j2 = max(j1 + j2 - x, 0)
    print("Current state:", (j1, j2))

print("Goal state reached: ({}, {})".format(goal_j1, goal_j2))
