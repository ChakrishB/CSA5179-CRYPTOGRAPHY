 #include <stdio.h>
#include <ctype.h>
void caesarEncrypt(char message[], int key) {
    char ch;
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        if (isalpha(ch)) {
            if (isupper(ch))
                ch = (ch + key - 'A') % 26 + 'A';
            else
                ch = (ch + key - 'a') % 26 + 'a';
        }
        message[i] = ch;
    }
}
void caesarDecrypt(char message[], int key) {
    caesarEncrypt(message, -key);
}
int main() {
    char message[100];
    int i, key;
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    for (key = 1; key <= 25; key++) {
        char encryptedMessage[100];
        for (i = 0; message[i] != '\0'; i++) {
            encryptedMessage[i] = message[i];
        }
        caesarEncrypt(encryptedMessage, key);
        printf("Key %d: %s", key, encryptedMessage);
    }
    for (key = 1; key <= 25; key++) {
        char decryptedMessage[100];
        for (i = 0; message[i] != '\0'; i++) {
            decryptedMessage[i] = message[i];
        }
        caesarDecrypt(decryptedMessage, key);
        printf("Decrypted with key %d: %s", key, decryptedMessage);
    }
}
