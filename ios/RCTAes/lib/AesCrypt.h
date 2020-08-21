//
//  AesCrypt.h
//
//
//  TaeHeun Lee (nixstory@gmail.com)

#import <Foundation/Foundation.h>

@interface AesCrypt : NSObject
+ (NSString *) encrypt: (NSString *)clearText  key: (NSString *)key iv: (NSString *)iv;
+ (NSString *) decrypt: (NSString *)cipherText key: (NSString *)key iv: (NSString *)iv;
+ (NSString *) pbkdf2:(NSString *)password salt: (NSString *)salt cost: (NSInteger)cost length: (NSInteger)length;
+ (NSString *) toHex: (NSData *)nsdata;
+ (NSString *) randomKey: (NSInteger)length;
+ (NSData *) fromHex: (NSString *)string;
@end
