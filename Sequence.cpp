#include"Sequence.h"
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
using namespace std;

Sequence::Sequence(string filename)
{
	ifstream in("dna.txt");
	string line;
	if (in)
	{
		while (getline(in, line))
		{
			for (int i = 0; i <= line.length(); i++)
			{
				if (line[i] == 'A')
				{
					a++;
				}
				else if (line[i] == 'T')
				{
					t++;
				}
				else if (line[i] == 'C')
				{
					c++;
				}				
			}
                        dna += line;
			le += line.length();
		}
	}
}

int Sequence::length()
{
	return le;
}

int Sequence::numberOf(char base)
{
	if (base == 'A')
	{
		return a;
	}
	else if (base == 'T')
	{
		return t;
	}
	else if (base == 'C')
	{
		return c;
	}
	else if (base == 'G')
	{
		return le-a-t-c;
	}
}

string Sequence::longestConsecutive()
{
	string def = "";
	int i;
	int max = 0;
	int k = 0;
	char x = dna[0];
	for (i = 1; i < le; ++i)
	{
		if (dna[i] == dna[i + 1])
		{
			k++;
			if (k > max)
			{
				x = dna[i];
				max = k;
			}
		}
                else
		{
                        k = 0;
                }
	}
	for (int j = 0; j <= max; j++)
	{
		def += x;
	}
	return def; 
}

int cmpLen(char* p, char* q)
{
	int l = 0;
	while ((*p) && (*(p++) == *(q++)))
	{
		l++;
	}
	return l;
}

int cmp(const void* p, const void* q)
{
	return strcmp(*(char* const*)p, *(char* const*)q);
}

string Sequence::longestRepeated()
{
	char* sa[1200000];
	char* str = const_cast<char*>(dna.c_str());
	int j = 0;
        char* maxp;
	int max = INT_MIN;
	int maxi = 0;
	int temp = 0;
	for (int k = 0; k < le; k++)
	{
		sa[k] = &dna[k];
	}
	qsort(sa, le, sizeof(char*), cmp);
	for (; j < le - 1; j++)
	{
		temp = cmpLen(sa[j], sa[j + 1]);
		if (temp > max)
		{
			maxi = j;
			maxp = sa[j];
		}
	}
	stringstream stream;
	for (char* k = maxp; k < max + maxp; k++)
	{
		stream << (*k);
	}
	return stream.str();
}
