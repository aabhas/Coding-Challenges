
#include <iostream>


Node* last_in = NULL;
uint* data;

//linked list's node structure
struct Node
{
	uint val;
	Node* next;
} Node;

//API's buffer class.
class buffer{
	public:
		uint* bytes;
		uint* set_buffer();
		uint* get_buffer();
};


//Space complexity:	O(n)
//Time complexity:	O(n)
/*
	set_buffer()
	description:	This function reads data from an input_stream() and copies it over
					to a buffer.
					Note: buffer is a linked list where each node copies over the data 
						  contained in each cell of the input_stream array.
*/
void buffer::set_buffer(uint* input_stream)
{
	
	int size_node = sizeof(Node); //bytes of one structure
	int num_nodes = sizeof(input_stream)/size_node;

	for(int i =0; i < num_nodes; i++)
	{
			Node curr = new Node();
			curr->val = *input_stream[i];	
	
			if(last_in = NULL)
				bytes = curr;

			last_in->next = curr;
			last_in = curr;
	}
	return;
}

//Space complexity: O(n)
//Time complexity:	O(n)
/*
	get_buffer()
	description:	This function reads data from the API created linked list. It then 
					copies over this data into an application's local data storage.
					Note: I have assumed the app's local data storage is also a linked
						  list.
*/
uint* buffer::get_buffer(Node* data)
{
	Node* curr = bytes;
	Node* dat = data;
	while(dat != NULL)
	{
		data->val = curr->val;
		curr = curr->next;
		dat = dat->next;
	}
}
