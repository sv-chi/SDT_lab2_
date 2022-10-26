#include "observer.h"

using namespace std;

 //следим за состоянием файла
void FileObserver::Update(bool existence, long size) {
    if (lastSize == -1) //если это только первый вызов,
        lastSize = size;//то обновляем размер
        if (existence) {//если файл существует
            if (lastSize != size) {//если изменился размер,
                cout << "File is existung, file has been changed, size: " << size << endl;
                lastSize = size;//то обновляем размер
            }
            else {
                cout << "File is existing, size: " << lastSize << endl;//файл существует и его размер
            }
        }
        else {
            cout << "File is not existing" << endl;//файл не существует
        }
    //cout << "called" << endl;
}
