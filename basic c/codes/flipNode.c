Node* flip(Node* _n)
{
	Node* temp;
	if(NULL==_n->m_next)
	{
		return _n;
	}
	
	temp=flip(_n->m_next);
	_n->m_next->m_next=_n;
	_n->m_next=NULL;
}

