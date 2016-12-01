#include "crypt.h"
#include </usr/local/include/gcrypt.h>
#include </usr/local/include/gpg-error.h>
#include <QDebug>
#include <vector>
#include <iostream>

Crypt::Crypt()
{

}




std::string Crypt::myCrypt(std::string text, std::string log, std::string pas)
{
    std::string plaintext=text;
    Botan::secure_vector<uint8_t> pt(plaintext.data(), plaintext.data() + plaintext.length());
    const std::vector<uint8_t> key = Botan::hex_decode(log + pas);
    std::unique_ptr<Botan::Cipher_Mode> enc(Botan::get_cipher_mode("AES-128/CBC/PKCS7", Botan::ENCRYPTION));
    enc->set_key(key);
    std::unique_ptr<Botan::RandomNumberGenerator> rng(new Botan::AutoSeeded_RNG);
    std::vector<uint8_t> iv(enc->default_nonce_length());
    rng->randomize(iv.data(), iv.size());
    enc->start(iv);
    enc->finish(pt);
    return Botan::hex_encode(pt);
}



