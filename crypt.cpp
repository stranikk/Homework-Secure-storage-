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

        Botan::SymmetricKey key (log+pas);//log=papa pas=mama equal to log=papam pas=ama
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




