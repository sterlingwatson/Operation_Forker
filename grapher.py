import graphviz

def build_tree(processes, parent):

    if parent not in processes:
        return None

    tree = graphviz.Digraph()
    tree.node(parent)

    for child in processes[parent]:
        tree.node(child)
        tree.edge(parent, child)
        sub_tree = build_tree(processes, child)
        if subTree:
            tree.subgraph(subTree)
    return tree

def parse_file(file_path):
