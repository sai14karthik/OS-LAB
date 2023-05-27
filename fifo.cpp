#include <iostream>
using namespace std;
int main()
{
int pageFaults = 0;
int frames;
int pages;
cout << "Enter the number of frames: ";
cin >> frames;
cout << "Enter the number of pages in the incoming stream: ";
cin >> pages;
int incomingStream[pages];
cout << "Enter the elements of the incoming stream: ";
for (int i = 0; i < pages; i++)
{
cin >> incomingStream[i];
}
cout << "Incoming\t";

for(int i=0;i<frames;i++){
cout<<"\tFrame"<<i+1<<"\t\t";
}
int temp[frames];
for (int m = 0; m < frames; m++)
{
temp[m] = -1;
}
for (int m = 0; m < pages; m++)
{
int s = 0;
for (int n = 0; n < frames; n++)
{
if (incomingStream[m] == temp[n])
{
s++;
pageFaults--;
}
}
pageFaults++;
if ((pageFaults <= frames) && (s == 0))
{
temp[m] = incomingStream[m];
}
else if (s == 0)
{
temp[(pageFaults - 1) % frames] = incomingStream[m];
}
cout << endl;
cout << incomingStream[m] << "\t\t\t";
for (int n = 0; n < frames; n++)
{
if (temp[n] != -1)

cout << temp[n] << "\t\t\t";
else
cout << "-\t\t\t";
}
}
cout<<endl;
cout<< "\nTotal Page Faults:\t" << pageFaults << endl;
return 0;
}
