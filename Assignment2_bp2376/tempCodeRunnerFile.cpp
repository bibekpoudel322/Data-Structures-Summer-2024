int Tree::size(Node *node)
{
	int n = 1; // count the current node
	for (Node *child : node->children)
	{
		n += size(child); // recursive call to count the children
	}
}