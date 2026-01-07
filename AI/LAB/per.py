# Define Unit Step Function
def unitStep(v):
    if v >= 0:
        return 1
    else:
        return 0

# Design Perceptron Model
def perceptronModel(x, w, b):
    # Calculate the dot product manually
    v = sum(wi * xi for wi, xi in zip(w, x)) + b
    y = unitStep(v)
    return y
  
# NOT Logic Function
# wNOT = -1, bNOT = 0.5
def NOT_logicFunction(x):
    wNOT = -1
    bNOT = 0.5
    return perceptronModel([x], [wNOT], bNOT)  # Single input as a list

# AND Logic Function
# w1 = 1, w2 = 1, bAND = -1.5
def AND_logicFunction(x):
    w = [1, 1]
    bAND = -1.5
    return perceptronModel(x, w, bAND)

# NAND Logic Function
# with AND and NOT  
# Function calls in sequence
def NAND_logicFunction(x):
    output_AND = AND_logicFunction(x)
    output_NOT = NOT_logicFunction(output_AND)
    return output_NOT
  
# Testing the Perceptron Model
test1 = [0, 1]
test2 = [1, 1]
test3 = [0, 0]
test4 = [1, 0]
  
print("NAND({}, {}) = {}".format(0, 1, NAND_logicFunction(test1)))
print("NAND({}, {}) = {}".format(1, 1, NAND_logicFunction(test2)))
print("NAND({}, {}) = {}".format(0, 0, NAND_logicFunction(test3)))
print("NAND({}, {}) = {}".format(1, 0, NAND_logicFunction(test4)))

