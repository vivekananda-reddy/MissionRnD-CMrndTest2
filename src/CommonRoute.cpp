/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

int issubstring(char*, char*, int, int);
char * find_common_route(char * hacklist, char *codelist, int *cost){
	int i, j=0, lmax = 0, a[200] = { 0 },index=0,ans[2],maxcost=0,k,sum=0,x;

	if (hacklist == NULL || codelist == NULL || cost == NULL)
	{
		return NULL;
	}
	
	for (i = 0; hacklist[i] != '\0'&&hacklist[j]!='\0'; i++)
	{
		x = issubstring(hacklist, codelist, i, j);
		while ( x )
		{
			if (j - i+1 > lmax)
			{
				a[0] = i;
				a[1] = j;
				index = 2;
				lmax = j - i + 1;
			}
			else if (j - i+1 == lmax)
			{
				a[index] = i;
				index++;
				a[index] = j;
				index++;
			}
			j++;
			if (hacklist[j] == '\0')
				break;
			x = issubstring(hacklist, codelist, i, j);
		}
		if (i == j||lmax>j-i)
		{
		
			j++;
		}
	
		
	}
	for (k = 0; k < index; i=i+2)
	{
		sum = 0;
		for (i = a[k]; i < a[k + 1]; i++)
		{
			sum = sum + hacklist[i];
		}
		if (sum > maxcost)
		{
			ans[0] = a[k];
			ans[1] = a[k + 1];
			maxcost = sum;
		}
		else if (sum == maxcost)
		{
			if (hacklist[ans[0]]<hacklist[a[k]])
			{
				continue;
			}
			else
			{
				ans[0] = a[k];
				ans[1] = a[k+1];
			}
		}
	}
	char *path = (char*)malloc(sizeof(char)*(ans[1] - ans[0] + 1));
	for (k = ans[0]; k <= ans[1]; k++)
	{
		path[k - ans[0]] = hacklist[k];
	}
	path[k - ans[0]] = '\0';
	*cost = maxcost;
	return path;
}

int issubstring(char*hacklist, char*codelist, int start, int end)
{
	int i, j,count=1,k;
	for (i = 0; codelist[i] != '\0'; i++)
	{
		count = 1;
		if (codelist[i] == hacklist[start])
		{
			j = start + 1;
			k = i + 1;
			while ( j<= end)
			{
				if (codelist[k] != hacklist[j])
				{
					count = 0;
					break;
				}
				j++;
				k++;
			}
			if (count == 1)
			{
				return 1;
			}
		}
	}
	return 0;

}