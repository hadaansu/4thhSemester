# Define the regions and their domains
regions = ['WA', 'NT', 'SA', 'Q', 'NSW', 'V']
colors = ['Red', 'Green', 'Blue']

# Define the constraint function
def const_different(color1, color2):
    return color1 != color2

# Define the constraints as pairs of (region1, region2)
constraints = [
    (('WA', 'NT'), const_different), 
    (('WA', 'SA'), const_different), 
    (('SA', 'NT'), const_different), 
    (('SA', 'Q'), const_different), 
    (('NT', 'Q'), const_different), 
    (('SA', 'NSW'), const_different), 
    (('Q', 'NSW'), const_different), 
    (('SA', 'V'), const_different), 
    (('NSW', 'V'), const_different), 
]

# Function to check if the current assignment is valid
def is_valid(assignment, region, color):
    for (region1, region2), constraint in constraints:
        if region == region1 and region2 in assignment:
            if not constraint(color, assignment[region2]):
                return False
        elif region == region2 and region1 in assignment:
            if not constraint(color, assignment[region1]):
                return False
    return True

# Backtracking function to solve the CSP
def backtrack(assignment):
    if len(assignment) == len(regions):
        return assignment  # All regions are assigned

    # Select the next unassigned region
    unassigned_region = [r for r in regions if r not in assignment][0]

    for color in colors:
        if is_valid(assignment, unassigned_region, color):
            assignment[unassigned_region] = color  # Assign color
            result = backtrack(assignment)  # Recur
            if result:
                return result
            del assignment[unassigned_region]  # Remove assignment (backtrack)

    return None  # No valid assignment found

# Solve the map coloring problem
solution = backtrack({})

# Print the result
if solution:
    print("Coloring solution found:")
    for region, color in solution.items():
        print(f"{region}: {color}")
else:
    print("No solution found.")
