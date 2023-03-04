import graphviz

#global root value
global root

def build_tree(nodes, parent, distance = 0):

    #error checking
    if parent not in nodes:
        return None

    tree = graphviz.Digraph()
    #a formatted string which combines the pid with the distance
    label = f"{parent}\nLevel: {distance}"
    tree.node(parent, label=label)

    for child in nodes[parent]:
        child_level = distance + 1
        tree.node(child, label=f"{child}\nLevel: {child_level}")
        tree.edge(parent, child)
        sub_tree = build_tree(nodes, child, child_level)
        #recursive call
        if sub_tree:
            tree.subgraph(sub_tree)
    return tree

#function to parse a file. It also assigns the root.
def parse_file(file_path):
    global root
    root = None
    nodes = {}
    with open(file_path, 'r') as file:
        #skip the first line of the file
        next(file)
        for line in file:
            child, parent = line.strip().split(',')
            #assign the root here
            if root is None:
                root = parent

            if parent not in nodes:
                nodes[parent] = []
            nodes[parent].append(child)
        return nodes

if __name__ == '__main__':

    file_path = 'input_n_4'
    nodes = parse_file(file_path)
    tree = build_tree(nodes, root,0)
    tree.render(view=True)
