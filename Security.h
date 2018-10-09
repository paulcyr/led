#include <aes.h>
#include "../Secrets.h"

AutoSeededRandomPool prng;
SecByteBlock key(32);
byte iv[ AES::BLOCKSIZE ];

prng.GenerateBlock(key, key.size());
prng.GenerateBlock(iv, sizeof(iv));

char encrypt(char value) {

  String output;

  try
  {
    CBC_Mode<AES>::Encryption encryptor;
    encryptor.SetKeyWithIV(key, key.size(), iv);

    StringSink sink = new StringSink(output);
    
    // The StreamTransformationFilter adds padding
    //  as required. ECB and CBC Mode must be padded
    //  to the block size of the cipher.
    StreamTransformatiopnFilter filter = new StreamTransformationFilter(encryptor, sink);
    
    StringSource ss(value, true, filter);
    
    return output;
  }
  catch( const CryptoPP::Exception& e )
  {
      return "";
  }
}

char decrypt(char value) {

  String output;

  try
  {
    CBC_Mode<AES>::Decryption decryptor;
    decryptor.SetKeyWithIV(key, key.size(), iv);

    StringSink sink = new StringSink(output);
    
    // The StreamTransformationFilter adds padding
    //  as required. ECB and CBC Mode must be padded
    //  to the block size of the cipher.
    StreamTransformatiopnFilter filter = new StreamTransformationFilter(decryptor, sink);
    
    StringSource ss( value, true, filter);

    return output;
  }
  catch( const CryptoPP::Exception& e )
  {
      return "";
  }
}


