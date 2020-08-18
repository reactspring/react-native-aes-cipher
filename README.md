# React Native AES

AES encryption/decryption for react-native

## Installation

```sh
npm install --save react-native-aes-cipher
```

or

```sh
yarn add react-native-aes-cipher
```

### Installation (iOS)

##### Using CocoaPods (React Native 0.60 and higher)

```sh
cd ios
pod install
```

### Installation (Android)

##### React Native 0.60 and higher
- Linking is done automatically

## Usage

### Example

```js
import { NativeModules, Platform } from 'react-native'
var Aes = NativeModules.Aes

const generateKey = (password: string, salt: string, cost: number, length: number) => Aes.pbkdf2(password, salt, cost, length)

const encryptData = (text: string, key: any) => {
    return Aes.randomKey(16).then((iv: any) => {
        return Aes.encrypt(text, key, iv).then((cipher: any) => ({
            cipher,
            iv,
        }))
    })
}

const encryptDataIV = (text: string, key: any, iv:any) => {
  return Aes.encrypt(text, key, iv).then((cipher: any) => ({
    cipher,
    iv,
  }))      
}

const decryptData = (encryptedData: { cipher: any; iv: any; }, key: any) => Aes.decrypt(encryptedData.cipher, key, encryptedData.iv)
```

#### Key Generation
```ts
  private AESKey () {
    try {
      generateKey('nixstory@gmail.com', 'SALT', 1000, 256).then((key: any) => {
        encrypt_key = key;
      })
    } catch (e) {
        console.error(e)
    }    
  }
  
#### Encrypt
```ts
  private AESEncrypt () {
    const key = encrypt_key;
    const iv_string = '0123456789abcdef0123456789abcdef';

    try {
      encryptDataIV(plain_string, key, iv_string).then(({ cipher, iv }) => {
        encrypt_iv = iv;
        encrypt_string = cipher;
      }).catch((error: any) => {})
    } catch (e) {
        console.error(e)
    }
  }
```

#### Descrpy
```ts
  private async AESDecrypt () {
    const key = encrypt_key;
    const iv = encrypt_iv;
    const cipher = encrypt_string;

    try {
      var decrypt_string = await decryptData({ cipher, iv }, key);

      console.log ("plain text : " + decrypt_string);
    } catch (e) {
        console.error(e)
    }
  }
```
