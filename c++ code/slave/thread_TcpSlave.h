#pragma once

#include <QThread>
#include <QDebug>

#include <stdio.h>  
#include <winsock2.h>
#include<WS2tcpip.h>
#include<iostream>

#pragma comment(lib, "ws2_32.lib")

extern QString current_NO;

class thread_Tcpslave : public QThread {
	Q_OBJECT
public:
	thread_Tcpslave();



protected:
	void run();

private:
	//char* recording = "recording";
	char revData[255];

signals:
	void slave_record(bool);
	void TCP_status(std::string);
	void slave_del(QString);
};