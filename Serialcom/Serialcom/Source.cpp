#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"
#include <conio.h>

using std::cout;
using std::endl;

char *port_name = "\\\\.\\COM8";

char incomingData[MAX_DATA_LENGTH];

int main()
{
	SerialPort arduino(port_name);
	if (arduino.isConnected()) 
		cout << "Connection Established" << endl;
	else cout << "ERROR:check port name";

	while (arduino.isConnected())
	{
		//read
		if (arduino.readSerialPort(incomingData, MAX_DATA_LENGTH)>0)
		{
			
			cout << incomingData;
		}

		//write
		if (_kbhit())
		{
			char d = _getch();
			arduino.writeSerialPort(&d,sizeof(char));
		}

		
		Sleep(100);
	}

	system("pause");
	return 0;
}