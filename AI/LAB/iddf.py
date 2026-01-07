
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': [],
    'E': [],
    'F': [],
    'G': []
}


def dfs(start, goal, depth_limit, visited, path):
    visited.add(start)  
    path.append(start)     
    if start == goal:
        return "FOUND", path    
    if depth_limit <= 0:
        return "NOT_FOUND", path   
    for child in graph[start]:
        if child not in visited:
            result, traversed_path = dfs(child, goal, depth_limit - 1, visited, path)
            if result == "FOUND":
                return "FOUND", traversed_path   
    return "NOT_FOUND", path


def iddfs(start, goal):
    depth_limit = 0
    while True:
        visited = set() 
        path = [] 
        result, traversed_path = dfs(start, goal, depth_limit, visited, path)
        print(f"Depth {depth_limit}: Traversed path: {traversed_path}")
        if result == "FOUND":
            return f"Goal node '{goal}' found! Path: {traversed_path}"
        depth_limit += 1       
        if depth_limit > len(graph):
            return "Goal node not found!"


start = input('Enter the start node: ')
goal = input('Enter the goal node: ')
result = iddfs(start, goal)
print(result)
