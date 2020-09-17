#include "flexible.h"

using namespace std;


// The constructor creates a unique_ptr to a dynamically allocated array of two
// CharacterBlocks using the initialization list syntax. No need to change this
// unless you add fields to the FlexibleCharacterManager.
FlexibleCharacterManager::FlexibleCharacterManager() : blocks(new CharacterBlock[2] {}) {}

//General idea but not quite correct

char* FlexibleCharacterManager::alloc_chars(size_t n) {
	int openspot1 =- 1;
  if(n <= bloacks{ 
    if(usable_mem_size==0){   
      Mem_Block **temp = NULL;
      temp = new Mem_Block*[active_requests];
     
      for(int j=0; j<active_requests; j++){
        temp[j] = new Mem_Block(used_memory[j]->size, used_memory[j]->physical_location);
      }
      for(int j=0; j<active_requests; j++){
        delete used_memory[j];
      } 
      delete []used_memory;
      used_memory = new Mem_Block*[active_requests*2];
     
      for(int i=0; i<active_requests;i++){
        used_memory[i] = new Mem_Block(temp[i]->size, temp[i]->physical_location);  
      } 
      for(int j=active_requests; j<active_requests*2;j++){
        used_memory[j] = NULL;
      }
      for(int j=0; j<active_requests; j++){
        delete temp[j];
      }
      delete []temp;
    
      usable_mem_size = active_requests;      
    } 
 
   firstopenspot = BUF_SIZE-free_mem;      
   free_place = &buffer[firstopenspot];
   used_memory[active_requests] = new Mem_Block(n,&buffer[firstopenspot]);   
   active_requests++;
   usable_mem_size--;
   free_mem = free_mem-n;   
  }
  return free_place;
}

void FlexibleCharacterManager::free_chars(char* p) {
	
  int memindex = 0;
  int bindex=-1; 
  int size = 0;
  for(int i=0; i<active_requests; i++){
    if(p==(used_memory[i]->physical_location)){
      size = used_memory[i]->size;
      bindex=0;
      
      delete used_memory[i];
      used_memory[i]=NULL;
      memindex = i;
     
      for(int j=memindex; j<active_requests-1; j++){
        used_memory[j]= new Mem_Block(used_memory[j+1]->size, used_memory[j+1]->physical_location);
        delete used_memory[j+1];
        used_memory[j+1]=NULL;
      }
      break;
    }
  }

  if(bindex>=0){
    for(int j=0; j<BUF_SIZE; j++){
      if(&buffer[j]==p){
        bindex=j;
        break;
      }
    }
    for(int i=bindex; i<bindex+size; i++){
      buffer[i] = '\0';
      p[i-bindex] = '\0';
    }
    p = NULL;
    active_requests--;
    usable_mem_size++;
  if(usable_mem_size > 4*active_requests && usable_mem_size>2){
    for(int j=(active_requests+usable_mem_size)/2; j<active_requests+usable_mem_size; j++){
      delete used_memory[j];
    }
    usable_mem_size = (active_requests+usable_mem_size)/2;
  }
  } 
}
