#include <iostream>

#include "Poco/Net/MulticastSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/NetException.h"
#include "Poco/Net/IPAddress.h"
#include "Poco/Net/IPAddressImpl.h"
#include "Poco/Timespan.h"
#include "Poco/Stopwatch.h"

using Poco::Net::Socket;
using Poco::Net::MulticastSocket;
using Poco::Net::SocketAddress;
using Poco::Net::IPAddress;
using Poco::Timespan;
using Poco::Stopwatch;
using Poco::TimeoutException;
using Poco::InvalidArgumentException;
using Poco::IOException;
using namespace std;

int main(){

    SocketAddress group("239.255.1.2", 12345);
    MulticastSocket ms;

    bool running = true;
    char key = 0;

    Poco::Timespan span(250000);

    while(running)
    {
        cin >> key;
        if( key == 'q') running = false;

        if( key == 's')
        {
            cout << "send to multicast group "<< group.toString()  <<"\n";
            int n = ms.sendTo("helloLo", 7, group);
            cout << n << " characters where sent\n";
        }


        if (ms.poll(span, Socket::SELECT_READ))
		{
            char buffer[256];
            //int n = ms.receiveBytes(buffer, sizeof(buffer));
            //cout << " Receive " << n << " bytes  ["<< buffer <<"]\n";
            SocketAddress from;
            int n = ms.receiveFrom(buffer, sizeof(buffer), from);
            cout << " Receive " << n << " bytes  ["<< buffer <<"] from "<< from.toString() <<"\n";
        }
        
        key = 0;
    }

    ms.close();

    return 0;
}

