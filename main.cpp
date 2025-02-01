#include <iostream>
#include "h/socket.h"
using namespace std;
 
int main()
{
	cppx::native::init(5);

	cppx::socket sock(cppx::protocol::tcp);
	if (!sock.not_invalid())
		return -1;
	if (!sock.connect(cppx::endpoint(cppx::ip_address::any, 7777)))
		return -1;

	cout << "connected" << endl;
}