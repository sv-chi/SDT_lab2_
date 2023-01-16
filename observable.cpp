#include "observable.h"
#include <sys/stat.h>

using namespace std;

// метод подписки объекта на оповещатель
void Observable::Attach(IObserver *observer){
    subscribers.push_back(observer);//добавляем наблюдателя
}
// метод удаления подписки объекта на оповещатель
void Observable::Detach(IObserver *observer){
    subscribers.erase(find(subscribers.begin(), subscribers.end(), observer));//удаляем по индексу наблюдателя
   }
// метод оповещения(наблюдатели обновляются независимо, учитывая текущее состояние
void Observable::Notify(bool existence, long size){
    //из вектора берем переменную (итератор - структура данных, которая может перебирать элементы)
    for(vector<IObserver*>::iterator iter = subscribers.begin(); iter != subscribers.end(); iter++) {
            if (*iter != 0) {//если указатель на итератор не нулевой
                (*iter)->Update(existence, size);//то у текущего наблюдателя вызываем Update и передаем туда значение
}
    }
       }
//проинициализировали prevFileState(_name) до того как сработал конструктор FileMonitor
FileMonitor::FileMonitor(std::string _name) : prevFileState(_name) { }
//проверяем состояние файла
void FileMonitor::checkFile() {
    FileInfo newFileState(prevFileState.name);//новый объект FileInfo
    Change(newFileState.existence, newFileState.size);//замечаем изменения(уведомляем подписчиков)
    prevFileState = newFileState;//обновляем состояние файла
}
//метод, который мы вызываем, когда в нашем файле произошли изменения
void FileMonitor::Change(bool existence, long size) {
    Notify(existence, size);
}
