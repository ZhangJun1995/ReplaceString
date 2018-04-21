/*****************************
*Name:  查找单词并替换
*Author: Zhang Jun
*Date: 2018/04/21
*****************************/

#include <iostream>
#include <string>
using namespace std;
//迭代器版本 
void replace_string(string s, const string oldval, const string newval) {
	for (auto ite = s.begin(); ite != s.end(); ++ite) {
		auto temp = ite;
		bool b = true;
		for (auto c = oldval.begin(); c != oldval.end() && temp != s.end(); ++c) {
			if (*temp != *c)
				b = false;
			++temp;
		}
		if (b == true && temp != ite && temp - ite == oldval.size()) {
			ite = s.erase(ite, temp);
			ite = s.insert(ite, newval.begin(), newval.end());
			ite += newval.size() - 1;
		}
	}
	cout << s;
}
//下标版本 
void replace_string2(string s, const string oldval, const string newval) {
	int p = 0;
	while ((p = s.find(oldval, p)) != string::npos) {
		s.replace(p, oldval.size(), newval);
		p += newval.size();
	}
	cout << s;
}
int main()
{
	const char *cp = "Hello Word I can realize my dream !";
	string s1(cp);
	string s2("can");
	string s3 = "must";
	cout << s1 << endl;
	replace_string(s1, s2, s3);
	replace_string2(s1, s2, s3);
	
	system("pause");
	return 0;
}

