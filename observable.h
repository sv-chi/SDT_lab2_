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
    vector<IObserver*> subscribers;//коллекция всех наблюдателей
public:
    void Attach(IObserver *observer);//добавить наблюдателя
    void Detach(IObserver *observer);//удалить наблюдателя
    void Notify(bool existence, long size);//оповещение всех наблюдателей
};

//Класс, в котором мы храним состояние и можем проверить файл и посмотреть изменения
//конкретное наблюдаемое, его состояние описывается FileInfo
class FileMonitor: public Observable {
private:
    FileInfo prevFileState;//здесь хранится прошлое файла
public:
    void Change(bool existence, long size);//метод, который мы вызываем, когда в нашем файле произошли изменения
    FileMonitor(string _name);
    void checkFile();//проверяем состояние файла
};

#endif // OBSERVABLE_H
