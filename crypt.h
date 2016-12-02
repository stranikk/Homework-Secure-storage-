#ifndef CRYPT_H
#define CRYPT_H


#include <QString>
#include </usr/local/include/botan/botan.h>
#include </usr/local/include/botan/pipe.h>
#include </usr/local/include/botan/aes.h>
#include </usr/local/include/botan/filters.h>
#include <QObject>
class Crypt
{
//Q_OBJECT
public:
    Crypt();
    std::string myCrypt(std::string text, std::string log, std::string pas, bool mode);
private:


};

#endif // CRYPT_H
