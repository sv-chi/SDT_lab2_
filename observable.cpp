#include "observable.h"
#include <sys/stat.h>

using namespace std;

// метод подписки объекта на оповещатель
void Observable::Attach(FileObserver *observer){
    subscribers.push_back(observer);//добавляем наблюдателя
}
// метод удаления подписки объекта на оповещатель
void Observable::Detach(FileObserver *observer){
    subscribers.erase(remove(subscribers.begin(), subscribers.end(), observer), subscribers.end());//удаляем
   }
// метод оповещения(наблюдатели обновляются независимо, учитывая текущее состояние
void Observable::Notify(bool existence, long size){
    for(vector<FileObserver*>::const_iterator iter = subscribers.begin(); iter != subscribers.end(); iter++) {
            if (*iter != 0) {
                (*iter)->Update(existence, size);
}
    }
       }

FileMonitor::FileMonitor(std::string _name) : prevFileState(_name) { }

void FileMonitor::checkFile() {
    FileInfo newFileState(prevFileState.name);//новое состояние файла
    Change(newFileState.existence, newFileState.size);//замечаем изменения
    prevFileState = newFileState;//обновляем состояние файла
}

void FileMonitor::Change(bool existence, long size) {
    Notify(existence, size);
}
