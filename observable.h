#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <string>
#include "observer.h"
#include <vector>
#include <fileinfo.h>

using namespace std;

//Класс отслеживает всех наблюдателей(можно добавлять и удалять наблюдателей)
class Observable
{
private:
    vector<FileObserver*> subscribers;//отслеживание всех наблюдателей
public:
    void Attach(FileObserver *observer);//добавить наблюдателя
    void Detach(FileObserver *observer);//удалить наблюдателя
    void Notify(bool existence, long size);//оповещение всех наблюдателей
};

//Класс, в котором мы храним предыдущее состояние и можем проверить файл и посмотреть изменения
class FileMonitor: public Observable {
private:
    FileInfo prevFileState;//здесь хранится прошлое файла
public:
    void Change(bool existence, long size);//изменения
    FileMonitor(string _name);
    void checkFile();//проверяем состояние файла
};

#endif // OBSERVABLE_H
