
#include"utility.h"
std::string hr = "* * * * * * * * * *";
#include"linkedlist.h"

void CopyLists(linkedlist&,linkedlist);

int main()
{
	div(hr);
	std::cout << "Testing LL to Functions" << std::endl;
	div(hr);

	linkedlist source;
	linkedlist target;
	
	std::cout << "Address of source: " << &source << "\nAddress of target: " << &target << "\n" << std::endl;
	
	for (int i=65; i < 91; i++) {
		source.add(ToString(char(i)) + " : " + ToString(i));
	}
	std::cout << "Initially: \n";
	std::cout << "Source contains: " << source.print() << "\n" << std::endl;
	
	std::cout << "Copying lists ... \n" << std::endl;
	CopyLists(target,source);

	std::cout << "Results: \n";
	std::cout << "Source contains: " << source.print() << "\n" << std::endl;
	std::cout << "Target contains: " << target.print() << "\n" << std::endl;

	// Exit program
	div(hr);
	return 0;
}

void CopyLists(linkedlist& t, linkedlist s) {
	std::cout << "Address of source (passed to function by value): " << &s << "\n";
	std::cout << "Address of target (passed to function by reference): " << &t << "\n" << std::endl;
	
	linkedlist* tmp = new linkedlist;
	
	while(s.size() > 0) {
		tmp->add(s.last());
		s.remove(s.last());
	}
	while(tmp->size() > 0) {
		t.add(tmp->last());
		tmp->remove(tmp->last());
	}
	
	std::cout << "End of CopyLists: size of tmp: " << tmp->size() << "\n" << std::endl;
	delete tmp;
}