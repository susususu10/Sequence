#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Sequence
{
public:
    Sequence(string filename);
    int length();
    int numberOf(char base);
    string longestConsecutive();
    string longestRepeated();
private:
    string dna;
    int le;
    int a;
    int t;
    int c;
    int g;
};

#endif
