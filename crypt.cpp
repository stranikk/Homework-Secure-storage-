#include "crypt.h"
#include <QDebug>
#include <vector>
#include <iostream>

Crypt::Crypt()
{
    Botan::InitializationVector init;
}




std::string Crypt::myCrypt(std::string text, std::string log, std::string pas, bool mode)
{
    /*
    std::string plaintext=text;
    Botan::secure_vector<uint8_t> pt(plaintext.data(), plaintext.data() + plaintext.length());
    const std::vector<uint8_t> key = Botan::hex_decode(log+pas);
    std::unique_ptr<Botan::Cipher_Mode> enc;
    if (mode==true){
        enc = std::unique_ptr<Botan::Cipher_Mode>(Botan::get_cipher_mode("AES-128/CBC/PKCS7", Botan::ENCRYPTION));
    }
    else{
        enc = std::unique_ptr<Botan::Cipher_Mode>(Botan::get_cipher_mode("AES-128/CBC/PKCS7", Botan::DECRYPTION));
    }
    enc->set_key(key);

    if(mode==true){
        std::unique_ptr<Botan::RandomNumberGenerator> rng(new Botan::AutoSeeded_RNG);
        std::vector<uint8_t> iv(enc->default_nonce_length());
        rng->randomize(iv.data(), iv.size());
        for(auto i = 0; i< iv.size(); ++i){
           iv1[i]=iv[i];
        }
        enc->start(iv);
        enc->finish(pt);
        return Botan::hex_encode(pt);
    }
   else{

        enc->start(iv1);
        enc->finish(pt);
        return Botan::hex_encode(pt);
    }
    */

        Botan::AutoSeeded_RNG rng;
        Botan::SymmetricKey key (log+pas);
        Botan::InitializationVector iv ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"); //initialis_vector must be 16*aa
        if(mode==true){
            Botan::Pipe pipe(Botan::get_cipher("AES-128/CBC",key,iv,Botan::ENCRYPTION),new Botan::Hex_Encoder);
            pipe.process_msg(text);
            std::string str = pipe.read_all_as_string(0);
            return str.data();
        }
        else{

            Botan::Pipe pipe1(new Botan::Hex_Decoder,Botan::get_cipher("AES-128/CBC",key,iv,Botan::DECRYPTION));
            pipe1.process_msg(text);
            std::string str1 = pipe1.read_all_as_string(0);
            return str1.data();
        }
}




