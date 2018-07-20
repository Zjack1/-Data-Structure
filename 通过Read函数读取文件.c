#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
 
template<typename T>
std::vector<T> ReadArray(std::ifstream &in, int size)   //size标识vector的大小
{
	std::vector<T> v(size, 0);
	in.read((char*)(&v[0]), sizeof(T)*size);
	return v;
}
 
int main() {
 
	ifstream in("TEST.txt");
	
	//获取文件的大小
	in.seekg(0, in.end);
	int length = in.tellg();
	in.seekg(0, in.beg);
 
	char* temp = new char[length];
 
	if (in.is_open()) {
		cout << "Now reading..." << endl;
		in.read(temp, length);
	}
	for (int i = 0; i < length; ++i)
	{
		cout << temp[i] <<" ";
	}
 
	cout << endl;
	
	in.seekg(0, in.beg);
	vector<char> textVec;
	textVec = ReadArray<char>(in, length);
	
	cout << textVec[1] << endl;
 
	in.close();
	system("PAUSE");
	
}
