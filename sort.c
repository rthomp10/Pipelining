#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
   const int NUMSTATES = 10;	//Max number of states
   const int STATELENGTH = 10; 	//abbreviation length for state
   char state[NUMSTATES][STATELENGTH];	//State string array
   char swap[STATELENGTH];	//Temporary variable for swapping
   
   //input
   for(int i = 0; i < NUMSTATES; i++)
   {
	   strcpy(state[i], " ");
	   scanf( "%s", state[i] );
   }
   printf("\n\n");
   
   //Sorts the states
    for(int i=0;i < NUMSTATES-1;i++)
   	{
   		for(int j=i+1;j < NUMSTATES;j++)
   		{
			//compares the next state
			if( strcmp(state[i],state[j]) > 1)
   			{
   				strcpy(swap,state[i]);
   				strcpy(state[i],state[j]);
   				strcpy(state[j],swap);
   			}
   		}
   	}
      
   //Sorted Output
   for(int i = 0; i < NUMSTATES; i++)
   {
	   if( strlen(state[i]) > 1 && strlen(state[i]) < 3) //Valid input checker
		   puts(state[i]);
   }
   return 0;
}

