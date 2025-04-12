def dfs(graph, source, sink):
    stack = [(source, [source])]
    all_paths = []

    while stack:
        current_node, path = stack.pop()

        if current_node == sink:
            all_paths.append(path)
        else:
            for neighbor in graph.get(current_node, []):
                if neighbor not in path:
                    stack.append((neighbor, path + [neighbor]))

    return all_paths

graph = {1: [2], 2: [1, 3, 5], 3: [2, 4, 5], 5: [2, 3, 6], 4: [3], 6: [5]}
source = 1
sink = 4

paths = dfs(graph, source, sink)

print(f"All paths from {source} to {sink}:")
for path in paths:
    print(*path, sep="->")
