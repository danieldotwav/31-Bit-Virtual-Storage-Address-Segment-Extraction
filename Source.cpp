#include <iostream>
#include <iomanip>
using namespace std;

void printFormattedResults(int a31bitAddress, int virtSegment, int virtPage, int virtOffset);

int main(int argc, char* argv[]) {
	int a31bitAddress = 0x02742008;
	int virtSegment, virtPage, virtOffset;

	// Use a bitwise AND operation with 0x00000fff to keep only the last 12 bits of the address, which represent the offset. 
	// This is because 0x00000fff in binary is 12 consecutive 1s, allowing the last 12 bits of a31bitAddress to pass through 
	// unchanged, while the rest are zeroed out.
	virtOffset = a31bitAddress & 0x00000fff;

	// Clears the segment bits(the most significant bits) by ANDing with 0x00ffffff and then shifts the 
	// result right by 12 bits to align the page number to the least significant bits.
	virtPage = a31bitAddress & 0x00ffffff;
	virtPage = virtPage >> 12;

	// Shift the entire address right by 24 bits to move the most significant 8 bits (the segment part of the address) 
	// to the position of the least significant bits, essentially extracting the segment number.
	virtSegment = a31bitAddress >> 24;

	printFormattedResults(a31bitAddress, virtSegment, virtPage, virtOffset);
	
	// Reset values
	virtSegment = 0;
	virtPage = 0;
	virtOffset = 0;

	return 0;
}

void printFormattedResults(int a31bitAddress, int virtSegment, int virtPage, int virtOffset) {
	cout << "C++ Output\n"
		<< "Original address:" << hex << setw(8) << setfill('0') << a31bitAddress << endl
		<< "Segment         :" << hex << setw(2) << setfill('0') << virtSegment << endl
		<< "Page            :  " << hex << setw(3) << setfill('0') << virtPage << endl
		<< "Offset          :     " << hex << setw(3) << setfill('0') << virtOffset << endl;
}