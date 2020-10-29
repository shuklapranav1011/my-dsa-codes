/*
Find Pair With Max XOR

input[] = {3,10,5,25,2,8};
output = 5^25 = 28;

Soln:-

3 - 0 0 0 1 1
10- 0 1 0 1 0
5 - 0 0 1 0 1
25- 1 1 0 0 1
2 - 0 0 0 1 0
8 - 0 1 0 0 0


//Maximum number of 1's starting from right to left (Msb to Left)
*/


/*
-----OPTIMIZED APPROACH-----
*/


class node
{
public:
	node* left;
	node* right;

	node()
	{
		left = NULL;
		right = NULL;
	}
};

class trie
{
	node*root;
public:
	trie()
	{
		root=new node();
	}

	//insert func;

	//for a 32 bit number
	void insert(int n)
	{
		node*temp = root;
		for(int i=31; i>=0;i--)
		{
			int bit = (n>>i)&1;
			//i zeros on the left of msb
			// to get right most bit

			if(bit == 0)
			{
				if(temp->left==NULL)
				{
					temp->left=new node();
				}
				temp= temp->left;
			}

			if(bit == 1)
			{
				if(temp->right==NULL)
				{
					temp->right=new node();
				}
				temp= temp->right;
			}
		}
	}

	int maxXOR(int n)
	{
		node*temp=root;
		int ans=0;
		for(int i=31; i>=0; i--)
		{
			int bit = (n>>i)&1;
			if(bit)
			{
				if(temp->left!=NULL)
				{
					temp= temp->left;
					ans = ans+ (1<<i);
				}
				else
				{
					temp= temp->right;
				}
			}
			else
			{
				if(temp->right != NULL)
				{
					temp=temp->right;
					ans = ans+ (1<<i);
				}
				else
				{
					temp=temp->left;
				}
			}
		}
		return ans;
	}
};

int main()
{
	int input[] = {3,10,5,25,2,8};

	trie t;
	for(int i=0; i<6 i++)
	{
		t.insert(input[i]);
	}

	int ans=0;
	for(int i=0;i<6;i++)
	{
		ans=max(ans, maxXOR(input[i]));
	}
	cout<<ans;
}