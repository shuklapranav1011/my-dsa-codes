#include <iostream>
#include <string>
using namespace std;

template <typename T>
class node
{

	#ifdef ONLINE_JUDGE
	//getting input from the input.txt
	freopen("intput.txt" , "r" , stdin);
	
	//writing output into output.txt
	freopen("output.txt" , "w" , stdout);
	
	#endif
	
    public:
    string key;
    T value;
    node* next;

    node(string key, T val)
    {
        this->key=key;
        value = val;
        next=NULL;
    }

    ~node()
    {
        if(next!=NULL)
            delete next; 
//this initiates the destructor node in the till NULL is found. 
    }
};

template <typename T>
class HashTable
{
    node <T> ** table;
    
    //table is a pointer to an array of pointers each containing string key, T value, node* next;
    //table is a member of the class

    int current_size;
    int table_size;

    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;
        for(int j=0;j<key.length();j++)
        {
            idx = idx + ( key[j] * p ) % table_size;
            idx = idx % table_size;
            p= ( p * 27 ) % table_size; 
        }
        return idx;
    }

    void rehash()
    {
    	node<T>**oldTable  = table; //note that tabel is a class member
    	int oldTablesize = table_size;

    	table_size = 2*table_size; 	
    	// we can also preferrably take next prime to table size

    	table = new node <T>*[table_size];
   

    	current_size = 0;

    	for(auto i=0; i<table_size; i++) 
    	{
    		table[i] = NULL;
    	}

    	for(auto i=0; i<oldTablesize; i++) 
    	{
    		node <T>*temp = oldTable[i];
    		while(temp != NULL)
    		{
    			insert(temp->key, temp->value);
    		//note that table is a class member so the insert fuction works on table.
    			temp = temp->next;
    		}
    		if(oldTable[i]!=NULL)
    			delete oldTable[i]; 
    		// we are calling a destructor of node class
    		// Node class destructor recursivly destructs whole linked list at oldTable[i] without us having to iterate over each element
    	}

    	delete [] oldTable;
    }

    public:
    HashTable(int ts=7) //we take a default table size of 7
    {
        table_size = ts;
        table = new node<T>*[table_size];
    //now array of size = table_size of T pointers created
        for(int i=0;i<table_size;i++)
        {
            table[i] = NULL;
        }  
    }

    void insert(string key , T value)
    {
        int idx = hashFn(key);
        node <T> *n = new node <T>(key,value);
        //Insert at head of the linked list with index = idx

        n->next = table[idx];
        table[idx] = n;
        current_size++;

        //rehash
        float load_factor = current_size/table_size;
        if(load_factor > 0.7)
        {
        	rehash();
        }
    }


    void print()
    {
    	for(auto i=0; i<table_size; i++) 
    	{
    		cout<<"Bucket "<<i<<"->";
    		node<T>*temp = table[i];
    		while(temp!=NULL)
    		{
    			cout<<temp->key<<"->";
    			temp=temp->next;
    		}
    		cout<<endl;
    	}
    }	
    

    T* search(string key)
    {
    	int idx = hashFn(key);
    	node<T>*temp = table[idx];
    	while(temp!=NULL)
    	{
    		if(temp->key==key)
    			return &temp->value;
    	}
    	return NULL;
    }

//using operator overloading for inserting and searching
    T& operator[](string key)
    {
    	if(search(key) == NULL)
    		//insert (key , garbage)
    		{
    			T garbage;
    			insert(key,garbage);
    		}
    	T* temp = search(key);
    	return *temp;
    }
   
};

int main()
{
//	HashTable <int> price_menu; // default size of table is taken = 7
//	HashTable <int> price_menu (45);  //size 45 is taken
	HashTable <int> price_menu (1);
	price_menu.insert("Burger" , 120);
	price_menu.insert("Coke" , 300);
	price_menu.insert("Pepsi" , 400);
	price_menu.insert("Paties" , 20);

	//if we update no. of keys greater than the 
	price_menu.print();

	auto isPresent = price_menu.search("Pepsi");
	cout<<*isPresent<<endl;


	//Insert
	price_menu["Dosa"] = 60;

	//Update
	price_menu["Dosa"] +=10;

	//Search
	cout<< price_menu["Dosa"] <<endl;


}