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
	auto context = new cppx::context;
	context->_buffer.insert(context->_buffer.end(), buf, buf + sizeof(buf));
	auto success = sock.send(context);
	if (success)
		cout << "send : " << context->_buffer.data() << endl;

	Sleep(1000);

	return 0;
}