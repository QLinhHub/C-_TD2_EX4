#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T, typename A, template <typename X, typename Y> class C>
std::ostream &operator<<(std::ostream &os, const C<T,A> &container)
{
 if(!container.empty())
   std::copy(container.begin(), container.end(), std::ostream_iterator<T>(os, " "));
 return os;
}

template<typename T> list<T> vector_to_list(const vector<T>& v){
	list<T> l;
	typename vector<T>::const_iterator it;
	for(it = v.begin(); it != v.end(); it++){
		l.push_back(*it);
	}
	return l;
}

int main()
{
	string str ("         ac ab aaaa this is my university. ffff t65 ffg 4    ");
	vector<string> vs;
	list<string> ls;
	unsigned int found = 0;
	unsigned int pos = 0;
	string s = "";
	while(found < str.size()){
        found = str.find(" ", pos);
        s = str.substr(pos, found-pos);
        if(found - pos != 0){
            pos = found + 1;
            vs.push_back(s);
        }
        else
            pos++;
	}

	ls = vector_to_list(vs);
	ls.sort();
	cout << ls << endl;
	return 0;
}
