#ifndef CRYPT_H
#define CRYPT_H

#include </usr/local/include/botan/hex.h>
#include </usr/local/include/botan/block_cipher.h>
#include </usr/local/include/botan/rng.h>
#include </usr/local/include/botan/auto_rng.h>
#include </usr/local/include/botan/cipher_mode.h>
#include </usr/local/include/botan/hex.h>
#include <QString>
#include <QObject>
class Crypt
{
//Q_OBJECT
public:
    Crypt();
    std::string myCrypt(std::string text, std::string log, std::string pas);
};

#endif // CRYPT_H
