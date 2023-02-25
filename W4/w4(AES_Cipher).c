#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>    //EVP

void crypt_both(int encrypt_or_decrypt, FILE* ifp, FILE* ofp, unsigned char* key, unsigned char* iv) 
{
    const unsigned BUFSIZE = 4096;
    int out_len;

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new(); //�ʱ�ȭ

    EVP_CipherInit(ctx, EVP_aes_256_cbc(), key, iv, encrypt_or_decrypt);    //�ʱ⼳��(EVP_aes_256_cbc)
 
    unsigned char* read_buf = malloc(BUFSIZE);
    unsigned char* cipher_buf = malloc(BUFSIZE + EVP_CIPHER_CTX_block_size(ctx));   //�� ũ��� �������ֱ� ����

    while (1) 
    {
        int numRead = fread(read_buf, 1, BUFSIZE, ifp); //fread�� ���� ���� ���� numRead�� ����
        
        EVP_CipherUpdate(ctx, cipher_buf, &out_len, read_buf, numRead); //��ȣȭ&��ȣȭ
        fwrite(cipher_buf, 1, out_len, ofp);
        if (numRead < BUFSIZE)
        { 
            break;
        }
    }

    EVP_CipherFinal(ctx, cipher_buf, &out_len); //����
    fwrite(cipher_buf, 1, out_len, ofp);

    EVP_CIPHER_CTX_free(ctx);
    free(cipher_buf);   //�޸� ����
    free(read_buf);
}

int main() 
{
    unsigned char key[1024];
    printf("Key�� �Է�: ");
    scanf("%s", key);          //Key �Է�
    unsigned char iv[512];
    printf("IV�� �Է�: ");
    scanf("%s", iv);           //IV �Է�

    int choice;
    printf("1 -> ����\n2 -> �����Է� ���ڿ�\n����: "); //�ɼ� ����
    scanf("%d", &choice);

    if (choice == 1)   // 1 -> ����
    {
        //��ȣȭ
        FILE* fA = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_before_encrypt.txt", "rb");    //��ȣȭ�� ���� �ּ�
        FILE* fB = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_after_encrypt.txt", "wb");     //��ȣȭ�� ���� �ּ�

        crypt_both(1, fA, fB, key, iv);   //��ȣȭ

        fclose(fA);
        fclose(fB);

        //��ȣȭ
        FILE* fC = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_after_encrypt.txt", "rb");   //��ȣȭ�� ���� �ּ�
        FILE* fD = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_after_decrypt.txt", "wb");   //��ȣȭ�� ���� �ּ�

        crypt_both(0, fC, fD, key, iv);  //��ȣȭ

        fclose(fC);
        fclose(fD);
    }
    else if (choice == 2)    //2 -> �����Է� ���ڿ�
    {
        char text[100];
        printf("Text�� �Է�: ");   //���ڿ� �Է�
        scanf("%s", &text);

        FILE* fE = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_before_encrypt.txt", "w");  //���Ϸ� ����
        fputs(text, fE);
        fclose(fE);

        FILE* fF = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_before_encrypt.txt", "rb");
        FILE* fG = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_after_encrypt.txt", "wb");     

        crypt_both(1, fF, fG, key, iv);     //��ȣȭ

        fclose(fF);
        fclose(fG);

        FILE* fH = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_after_encrypt.txt", "rb");   //��ȣȭ�� ���� �ּ�
        FILE* fI = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_after_decrypt.txt", "wb");   //��ȣȭ�� ���� �ּ�

        crypt_both(0, fH, fI, key, iv);    //��ȣȭ

        fclose(fH);
        fclose(fI);
    }
    else
    {
        printf("<error> 1, 2 �� �ϳ��� �� �� �ֽ��ϴ�.");
        return -1;
    }

    return 0;
}