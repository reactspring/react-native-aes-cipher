declare module '@reactspring/-cihper' {
    function pbkdf2(password: string, salt: string, cost: number, length: number): Promise<string>;
    function encrypt(text: string, key: string, iv: string): Promise<string>;
    function decrypt(ciphertext: string, key: string, iv: string): Promise<string>;
    function randomKey(length: number): Promise<string>;
}
