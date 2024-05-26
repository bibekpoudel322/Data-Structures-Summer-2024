Node *curr = head;
	Node *temp = tail;
	while (curr != temp)
	{
		if (curr->elem != temp->elem)
		{
			return false;
		}
		curr = curr->next;
		temp = temp->prev;
	}
	return true;