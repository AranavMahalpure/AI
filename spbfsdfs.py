from collections import deque

graph = {
    'A': ['B', 'C', 'E'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F', 'G'],
    'D': ['B'],
    'E': ['A', 'B', 'D'],
    'F': ['C'],
    'G': ['C']
}

def bfs(graph, initial):
    visited = []
    queue = deque([initial])
    
    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.append(node)
            neighbours = graph[node]
            for neighbour in neighbours:
                queue.append(neighbour)
    
    return visited

print(bfs(graph, 'A'))
