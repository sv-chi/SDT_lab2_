#ifndef FILEINFO_H
#define FILEINFO_H
#include <string>
#include <sys/stat.h>

using namespace std;
//класс, содержащий информацию о файле
class FileInfo
{
public:
    string name; // имя файла
    long size; // размер
    bool existence; // существование файла
    FileInfo(string fileName);//конструктор
};

#endif // FILEINFO_H
