#pragma once
template <class type>
class Node
{
    public:
    type data;
    Node *next;
    Node(){} //default constrcutor

    Node(type data) 
	{
		this->data = data; 
	}
};

