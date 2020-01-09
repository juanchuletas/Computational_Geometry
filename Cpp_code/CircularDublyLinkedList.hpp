class Node
{
	protected:
		Node *_next; //Link to succesor node
		Node *_prev; //Link to predecessor node 
	public:
		Node(void);
		virtual ~Node(void);
		Node *next(void);
}
