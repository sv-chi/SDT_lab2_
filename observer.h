#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include <iostream>

//Класс, в котором методы вызывается при каждом изменении
class IObserver {
public:
    virtual void Update(bool existence, long size) = 0;//метод обновления
};

//Класс, в котором вызываются уведомления об изменении файла
class FileObserver: public IObserver
{
private:
    long lastSize = -1;//здесь хранится последний размер файла
public:
    void Update(bool existence, long size);//уведомления об изменении файла
};

#endif // OBSERVER_H
