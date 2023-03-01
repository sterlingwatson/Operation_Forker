import graphviz

global root

def build_tree(processes, parent):

    if parent not in processes:
        return None

    tree = graphviz.Digraph()
    tree.node(parent)

    for child in processes[parent]:
        tree.node(child)
        tree.edge(parent, child)
        sub_tree = build_tree(processes, child)
        if sub_tree:
            tree.subgraph(sub_tree)
    return tree

def parse_file(file_path):
    global root
    root = None
    processes = {}
    with open(file_path, 'r') as file:
        next(file)
        for line in file:
            print(line)
            child, parent = line.strip().split(',')
            if root is None:
                root = parent

            if parent not in processes:
                processes[parent] = []
            processes[parent].append(child)
        return processes

if __name__ == '__main__':

    file_path = 'input.txt'
    processes = parse_file(file_path)
    print(root)
    tree = build_tree(processes, root)
    tree.render(view=True)
