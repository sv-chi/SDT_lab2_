#ifndef FILEINFO_H
#define FILEINFO_H
#include <string>
#include <sys/stat.h>

using namespace std;

class FileInfo
{
public:
    string name; // имя файла
    long size; // размер
    bool existence; // существование файла
    FileInfo(string fileName);
};

#endif // FILEINFO_H
