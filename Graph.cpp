public class Node{

	public List<Node> _children;
	public bool _marked;

	public Node(){
		_marked = false;
	}

	public addChildren(Node child){
		_children.add(child);
	}

	public bool routeBetweenNodes(Graph g, Node s, Node t){
		
	}
}