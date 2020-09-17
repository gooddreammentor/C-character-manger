#include "simple.h"

using namespace std;


char* SimpleCharacterManager::alloc_chars(size_t size) {
	// TODO: your implementation here
	int open_spot = 0;
	while(buffer[open_spot] != '\0' && open_spot < BUFFER_SIZE)
	{
		open_spot++
	}
	if(open_spot + size < BUFFER_SIZE)
	{
		first_available_address = &buffer[open_spot];
	}
	else{
		first_available_address = NULL;
	}
	return first_available_address;
}

void SimpleCharacterManager::free_chars(char* address) {
	// TODO: your implementation here
	ind = 0;
	while(ind < BUFFER_SIZE)
	{
		if(address == &buffer[ind])
		{
			break;
		}
		ind++; 
	}
	if(ind < BUFFER_SIZE)
	{
		for(int i = ind; i < BUFFER_SIZE; i++)
		{
			buffer[i] = '\0';
			address[i - ind] = '\0';
		}
	}
}
