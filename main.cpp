#include <iostream>
#include "socket.h"
using namespace std;
 
int main()
{
	cppx::native::init(5);

	cppx::socket sock(cppx::protocol::tcp);
	if (!sock.not_invalid())
		return -1;
	if (!sock.connect(cppx::endpoint(cppx::ip_address::loopback, 7777)))
		return -1;
	
	cout << "connected" << endl;

	char buf[1024] = "hello";
	auto success = sock.send(buf);
	if (success)
		cout << "send : " << buf << endl;

	Sleep(1000); 

	return 0;
}