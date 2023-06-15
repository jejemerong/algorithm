#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	char str1[] = "apple";
    char str2[] = {9, 0, 1, 3};
	string str4 = "melon";
	// TODO: vector size(), sizeof()
	vector<int> arr1 {5}; // 중괄호 -> 요소 3개 벡터 배열
	vector<int> arr2 [5]; // 대괄호 -> 벡터 배열 5개, 요소는 정의되지 않음.

	cout << " => "
		<< sizeof(str1) << "\n";

	cout << "strlen() 는 문자열 length 로 나옴. => "
		<< strlen(str1) << "\n"
		<< endl;

	cout << "int 배열의 sizeof 는 요소 개수로 나옴. =>"
		<< sizeof(str2) << "\n";

	// This method Works fine
	cout << "배열 하나의 개수로 나옴."
		<< strlen(str2) << "\n"
		<< endl;

	// This method always gives 32
	cout << "std::string object 바이트 길이는 24비트라서"
		<< sizeof(str4) << "\n";

	// This method works fine
	cout << "The length of str3 using size(): "
		<< str4.size() << "\n"
		<< endl;

	cout << "The length of vector arr1 using size(): " 
		<< arr1.size() << "\n"
		<< endl;

	cout << "The length of vector arr1 using sizeof()"
		<< sizeof(arr1) << "\n"
		<< endl;

	cout << "The length of vector arr2 using size(): " 
		// << arr2.size() << "\n" // member reference base type 'vector<int>[5]' is not a structure or union
		<< "식에 클래스 형식이 있어야 하는데 std::__1::vector<int, std::__1::allocator<int>> * 형식이 있음"
		<< "라는 에러 남."
		<< endl;

	cout << "The length of vector arr2 using sizeof()"
		<< sizeof(arr2) << "\n"
		<< endl;
}
