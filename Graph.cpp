public class Node{

	public List<Node> _children;
	public bool _marked;
	public int _data;
	public Node _left;
	public Node _right;

	public Node(){
		_marked = false;
	}

	public Node(int data){
		_data = data;
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

	public void buildTreeMinHt(int[] arr){
		MyQueue q = new MyQueue();
		int i = 0;
		Node curr = new Node(arr[i]);
		while(i < arr.length){
			if (((2^i)+1) < arr.length)
			{
				curr._left = new Node(arr[(2^i)+1]);
				q.add(curr._left);
				if (((2^1)+2) < arr.length)
				{
					curr._right = new Node(arr[(2^i)+2]);
					q.add(curr._right);
				}
			}

			curr = q.remove();
			i++;
			if(((2^i)+1) >= arr.length){
				return;
			}
		}
	}

	public Node createMinBST(int[] arr){
		return createMinBST(arr, 0, arr.length);
	}

	public Node createMinBST(int[] arr, int start, int end){
		if(end < start){
			return null;
		}

		int mid = (start + end)/2;
		Node n = new Node(arr[mid]);
		n._left = createMinBST(arr, start, mid-1);
		n._right = createMinBST(arr, mid+1, end);
		return n;
	}
}