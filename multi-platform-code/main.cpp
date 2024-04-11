#include "Poco/Thread.h"
#include "Poco/Environment.h"
#include "Poco/Runnable.h"
#include <iostream>
class ThreadTest: public Poco::Runnable
{
    virtual void run()
    {
        for(int i=0;i<10;i++){
            std::cout <<num<<"'s loop :" <<i<< std::endl;
        }
    }

public:
    void set(int arg){
        num = arg;
    }

private:
    int num;
};
#define LOOP_CNT 5
void InntroduceOs(){
    std::cout
            << "OS Name: " << Environment::osName() << std::endl
            << "OS Version: " << Environment::osVersion() << std::endl
            << "OS Arch: " << Environment::osArchitecture() << std::endl
            << "Node Name: " << Environment::nodeName() << std::endl
            << "Node ID: " << Environment::nodeId() << std::endl;
}
int main(int argc, char** argv)
{
    ThreadTest runnable[LOOP_CNT];
    for(int i=0;i<LOOP_CNT;i++){
        runnable[i].set(i);
    }

    Poco::Thread thread[LOOP_CNT];
    for(int i=0;i<LOOP_CNT;i++){
        thread[i].start(runnable[i]);
    }
    for(int i=0;i<LOOP_CNT;i++){
        thread[i].join();
    }
    return 0;
}