# React Native AES 128/192/256

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
- Linking automatically

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
const iv_string = '0123456789abcdef0123456789abcdef';

let encrypt_key:any = "";
let encrypt_string:any = "";
let plain_string:any = "1234567890";
let encrypt_iv:any = "";
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
```

#### Encrypt
```ts
  private AESEncrypt () {
    const key = encrypt_key;

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

#### Decrypt
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


#### IOS Test (Encrypt)
```ts
[Tue Aug 18 2020 15:31:58.668]  LOG      [encrypt] plain text : 1234567890
[Tue Aug 18 2020 15:31:58.670]  LOG      [encrypt] encrypt key : 591825e3a4f2c9b8f73eb963c77ad160d4802ad7aadc179b066275bcb9d9cfd2
[Tue Aug 18 2020 15:31:58.670]  LOG      [encrypt] iv : 0123456789abcdef0123456789abcdef
[Tue Aug 18 2020 15:31:58.671]  LOG      [encrypt] encrypt text : hg7zoTXoD/xbcvj64M0iYg==
```

#### ANDROID Test (Decrypt)
```ts
[Tue Aug 18 2020 15:56:21.306]  LOG      [decrypt] encrypt text : hg7zoTXoD/xbcvj64M0iYg==
[Tue Aug 18 2020 15:56:21.308]  LOG      [decrypt] encrypt key : 591825e3a4f2c9b8f73eb963c77ad160d4802ad7aadc179b066275bcb9d9cfd2
[Tue Aug 18 2020 15:56:21.309]  LOG      [decrypt] iv : 0123456789abcdef0123456789abcdef
[Tue Aug 18 2020 15:56:21.310]  LOG      [decrypt] plain text : 1234567890
```
