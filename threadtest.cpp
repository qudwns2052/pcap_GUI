#include "threadtest.h"

ThreadTest::ThreadTest(QObject *parent) :
    QThread(parent)
{
}

void ThreadTest::run()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);


    int value;

    while(1)
    {
        printf("\n--------------Packet Capture-------------\n");
        struct pcap_pkthdr* header;
        const u_char* packet;
        int res = pcap_next_ex(handle, &header, &packet);

        if (res == 0) continue;
        if (res == -1 || res == -2) break;


        value = (header->caplen) % 2;
        emit lenValue(value);

    }
    pcap_close(handle);

}
