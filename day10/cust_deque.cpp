#include<iostream>
using namespace std;



class simpleDeque
{

	static const int block_size=4;
	static  int table_size;

	int **block_table;
	int start_offset;
	int end_offset;
	int start_block;
	int end_block;
	int current_size;

	public:
	simpleDeque(){

		block_table=new int*[table_size];

		for(int i=0;i<table_size;i++)
			block_table[i]=nullptr;

		start_block=end_block=table_size/2;

		block_table[start_block]=new int[block_size];

		start_offset=0;
		end_offset=0;
		current_size=0;
	}

	void grow()
	{

		cout<<"\nrealloc is happend\n";
		
	       int old_table_size = table_size;
		table_size *= 2;

		int **newblock_table = new int*[table_size];

		for(int i=0;i<table_size;i++)
			newblock_table[i] = nullptr;

		int new_start = (table_size - (end_block - start_block + 1)) / 2;

		for(int i=start_block, j=new_start; i<=end_block; i++, j++)
			newblock_table[j] = block_table[i];

		delete [] block_table;

		end_block = new_start + (end_block - start_block);
		start_block = new_start;

		block_table = newblock_table;
	}




	void push_back(int value)
	{

		if(end_block==block_size-1 && end_offset==block_size-1)
			grow();



		if(end_offset==block_size)
		{
			end_block++;
			block_table[end_block]=new int[block_size];
			end_offset=0;
		}


		block_table[end_block][end_offset++]=value;
		current_size++;
	}

	int operator[](int index){
		int total_offset=start_offset+index;

		int block=start_block+(total_offset/block_size);
		int offset=total_offset%block_size;

		return block_table[block][offset];

	}


	void push_front(int value)
	{


		if(start_block==0 && start_offset==0)
			grow();

		if(start_offset>0)
		{
			start_offset--;
			block_table[start_block][start_offset]=value;
		}
		else
		{

			start_block--;

			block_table[start_block]=new int[block_size];


			start_offset=block_size-1;

			block_table[start_block][start_offset]=value;
		}

		current_size++;

	}


	int size()const
	{
		return current_size;
	}

	void Myclear(){

		for(int i=0;i<block_size;i++)
			delete [] block_table[i];

		delete [] block_table;

	}







};
int simpleDeque::table_size = 4;  // initial value


 
int main() {
   simpleDeque obj;

    for(int i=0;i<8;i++) obj.push_back(i);
    for(int i=0;i<8;i++) obj.push_front(i*2);

    for(int i=0;i<5;i++) obj.push_back(100+i);

    for (int i = 0; i < obj.size(); i++)
        cout << obj[i] << " ";
    cout << endl;

    return 0;
}

