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
		if( s==t){
			return true;
		}

		MyQueue q = new MyQueue();
		s._marked = true;
		q.add(s);

		while(!q.isEmpty()){
			Node curr = q.remove();
			for each (Node n in curr._children){
				if(n._marked == false){
					if (n == t)
					{
						return true;
					}

					n._marked = true;
					q.add(n);
				}
			}
		}

		return false;
	}
}