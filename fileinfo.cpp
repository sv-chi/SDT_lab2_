#include "fileinfo.h"

FileInfo::FileInfo(std::string fileName)
{
    name = fileName;
    struct stat stat_buf; //stat описывает состояние файла
    //Функция stat() вносит в структуру, на которую указывает statbuf,
    //информацию, содержащуюся в файле, связанном с указателем filename.
    //При успешном заполнении структуры stat возвращается 0.
    //В случае неудачи возвращается —1
    existence = stat(fileName.c_str(), &stat_buf) == 0; //если равно 0, то true
    size = stat_buf.st_size;//размер файла, который определяет буфер
}
