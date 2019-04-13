#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    unsigned long long int n,m,q;
    map<unsigned long long int,unsigned long long int> choco;
    scanf("%llu %llu %llu",&n,&m,&q);
	choco[0] = m+1;
	choco[n+1] = 0;
    while(q--)
    {
        unsigned long long int rn,rm;
        scanf("%llu %llu",&rn,&rm);
		if(rm > m)
			rm = m;
		if(rn > n)
			rn = n;
		unsigned long long int eat = 0;
		unsigned long long int prev = 0;
		bool eraser = false;
		map<unsigned long long int, unsigned long long int>::iterator eraser_f;
		map<unsigned long long int,unsigned long long int>::iterator eraser_l = choco.end();
		for(map<unsigned long long int,unsigned long long int>::iterator i = choco.begin();i!=choco.end();i++)
		{
			if(i->first > rn)
			{
				eraser_l = i;
				if(i->second < rm)
					eat+= (rn - prev)*(rm - i->second);
				break;
			}
			else if(i->second > rm)
			{
			}
			else 
			{
				eat += (i->first - prev) * (rm - i->second);
				if(!eraser)
				{
					eraser_f = i;
					eraser = true;
				}
			}
			prev = i->first;
		}
		
        if(eat >0)
		{
			if(eraser)
		    {
		        choco.erase(eraser_f, eraser_l);
		    }
		    choco[rn] = rm;
            printf("%llu\n",eat);
		}
        else
            printf("QAQ\n");
    }
    unsigned long long int prev = 0;
    unsigned long long int rem = 0;
    for(map<unsigned long long int,unsigned long long int>::iterator i = choco.begin();i!=choco.end();i++)
		{
			if(i->first > n)
			{
				if(i->second < m)
					rem+= (n - prev)*(m - i->second);
				break;
			}
			else if(i->second > m)
			{
				
			}
			else 
			{
				rem += (i->first - prev) * (m - i->second);
			}
			prev = i->first;
		}
    printf("%llu",rem);
    return 0;
}
