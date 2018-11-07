import acm.graphics.GOval;

/**
 * Implements a Binary tree class
 * @author Kevin
 *
 */


public class bTree {
	private static boolean BMRunning = true;
	public double ref = 0;
	bNode root = null;					// Default constructor
	
/**
 * addNode method - wrapper for rNode
 */	
	public void addNode(gBall iBall) {		// This is a wrapper to hide
		root = rNode(root, iBall);			// having to deal with root node.
	}									// Calls actual method below.
/**
 * rNode method - recursively adds a new entry into the B-Tree
 */	
	private bNode rNode(bNode root, gBall iBall) {
//
//  Termination condition for recursion.  We have descended to a leaf
//  node of the tree (or the tree may initially be empty).  In either case,
//	create a new node --> copy over data, set successor nodes to null.
//
		if (root == null) {
			bNode node = new bNode();	// Create a new node
			node.iBall = iBall;			// Copy data
			node.left = null;			// Successors to null.
			node.right = null;
			root = node;					// Node created is root
			return root;				// of new (sub) tree.
		}
//
//	Not at a leaf node, so traverse to the left if data being
//  added is strictly less than data at current node.
//
		else if (iBall.bSize < root.iBall.bSize) {
			root.left = rNode(root.left,iBall);
		}
//
//  If greater than or equal, then traverse to the right.  Keep
//  recursing until a node is found with no successors.
		else {
			root.right = rNode(root.right,iBall);
		}
		return root;
	}
	


	/**
	 * traverse_inorder method - recursively traverses tree in order and prints each node.
	 * Order: Descend following left successor links, returning back to the current
	 *        root node (where a specific action takes place, e.g., printing data),
	 *        and then repeat the descent along right successor links.
	 */
	
	private void ReRunning(bNode root) {
		if (root.left != null) ReRunning(root.left);
		if (root.iBall.ballRun == true) BMRunning = true;
		if (root.right != null) ReRunning(root.right);
	}
	
	//Wrapper class 
	public boolean isRunning() {
		BMRunning = false;
		ReRunning(root);
		return BMRunning;
	}
	
	//Sorting method
	public void moveSort() {
		ref = 0;
		Bsorting(root);
	}
	
	private void Bsorting(bNode root) {
		if (root.left!= null) {
			Bsorting(root.left);
		}
			root.iBall.myBall.setLocation(ref, bSim.HEIGHT - root.iBall.bSize * 2);
			ref += root.iBall.bSize * 2;
		


		if (root.right!= null) {
			Bsorting(root.right);
		}
	}
	
	public bNode findNode(GOval value) {
		 return findNodeRecursive(root, value);
		}
	
	
	private bNode findNodeRecursive(bNode current, GOval value) {
		if (root.left != null && current.iBall.myBall == value) findNodeRecursive(root.left, value);
		if (root.right != null && current.iBall.myBall == value) findNodeRecursive(root.right, value);
		return current;
	}
}
