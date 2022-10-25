#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <string>
#include "observer.h"
#include <vector>
using namespace std;

class Observable
{
private:
    vector<FileObserver*> subscribers;
public:
    void Attach(FileObserver *observer);
    void Detach(FileObserver *observer);
    void Notify();
};

class FileMonitor: public Observable {
public:
    void Change();
};

#endif // OBSERVABLE_H
