graph={
    's':[('a',1),('g',10)],
    'a': [('b', 2), ('c', 1)],
    'b': [('d', 5)],
    'c': [('d', 3),('g',4)],
    'd': [('g',2)],
    'g': []
}

heuristic = {
             's': 5,
             'a': 3,
             'b': 4,
             'c': 2,
             'd': 6,
             'g': 0
            }

def a_star(graph, heuristic, start,goal):
    open_list = set([start])
    closed_list = set([])       
    g = {}
    g[start] = 0        
    parents = {}
    parents[start] = start

    def get_neighbors(node):
        return graph[node]

    def h(node):
        return heuristic[node]

    while len(open_list) > 0:
        n = None            
        for v in open_list:
            if n == None or g[v] + h(v) < g[n] + h(n):
                n = v;

        if n == None:
            print('Path does not exist!')
            return None
        if n == goal:
            reconst_path = []
            while parents[n] != n:
                reconst_path.append(n)
                n = parents[n]
            reconst_path.append(start)
            reconst_path.reverse()

            print('Path found: {}'.format(reconst_path))
            return reconst_path

        for (m, weight) in get_neighbors(n):
            if m not in open_list and m not in closed_list:
                open_list.add(m)
                parents[m] = n
                g[m] = g[n] + weight
            else:
                if g[m] > g[n] + weight:
                    g[m] = g[n] + weight
                    parents[m] = n
                    if m in closed_list:
                        closed_list.remove(m)
                        open_list.add(m)
        open_list.remove(n)
        closed_list.add(n)

    print('Path does not exist!')
    return None

start = input("Enter the start node: ")
goal = input("Enter the stop node: ")
a_star(graph, heuristic, start,goal)

