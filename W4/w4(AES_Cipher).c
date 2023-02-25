#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>    //EVP

void crypt_both(int encrypt_or_decrypt, FILE* ifp, FILE* ofp, unsigned char* key, unsigned char* iv) 
{
    const unsigned BUFSIZE = 4096;
    int out_len;

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new(); //초기화

    EVP_CipherInit(ctx, EVP_aes_256_cbc(), key, iv, encrypt_or_decrypt);    //초기설정(EVP_aes_256_cbc)
 
    unsigned char* read_buf = malloc(BUFSIZE);
    unsigned char* cipher_buf = malloc(BUFSIZE + EVP_CIPHER_CTX_block_size(ctx));   //블럭 크기는 정해져있기 때문

    while (1) 
    {
        int numRead = fread(read_buf, 1, BUFSIZE, ifp); //fread로 읽은 원소 개수 numRead에 저장
        
        EVP_CipherUpdate(ctx, cipher_buf, &out_len, read_buf, numRead); //암호화&복호화
        fwrite(cipher_buf, 1, out_len, ofp);
        if (numRead < BUFSIZE)
        { 
            break;
        }
    }

    EVP_CipherFinal(ctx, cipher_buf, &out_len); //종료
    fwrite(cipher_buf, 1, out_len, ofp);

    EVP_CIPHER_CTX_free(ctx);
    free(cipher_buf);   //메모리 해제
    free(read_buf);
}

int main() 
{
    unsigned char key[1024];
    printf("Key를 입력: ");
    scanf("%s", key);          //Key 입력
    unsigned char iv[512];
    printf("IV를 입력: ");
    scanf("%s", iv);           //IV 입력

    int choice;
    printf("1 -> 파일\n2 -> 본인입력 문자열\n선택: "); //옵션 선택
    scanf("%d", &choice);

    if (choice == 1)   // 1 -> 파일
    {
        //암호화
        FILE* fA = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_before_encrypt.txt", "rb");    //암호화할 파일 주소
        FILE* fB = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_after_encrypt.txt", "wb");     //암호화될 파일 주소

        crypt_both(1, fA, fB, key, iv);   //암호화

        fclose(fA);
        fclose(fB);

        //복호화
        FILE* fC = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_after_encrypt.txt", "rb");   //복호화할 파일 주소
        FILE* fD = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\1_after_decrypt.txt", "wb");   //복호화될 파일 주소

        crypt_both(0, fC, fD, key, iv);  //복호화

        fclose(fC);
        fclose(fD);
    }
    else if (choice == 2)    //2 -> 본인입력 문자열
    {
        char text[100];
        printf("Text를 입력: ");   //문자열 입력
        scanf("%s", &text);

        FILE* fE = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_before_encrypt.txt", "w");  //파일로 저장
        fputs(text, fE);
        fclose(fE);

        FILE* fF = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_before_encrypt.txt", "rb");
        FILE* fG = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_after_encrypt.txt", "wb");     

        crypt_both(1, fF, fG, key, iv);     //암호화

        fclose(fF);
        fclose(fG);

        FILE* fH = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_after_encrypt.txt", "rb");   //복호화할 파일 주소
        FILE* fI = fopen("C:\\Users\\user\\Desktop\\my_AES_files\\2_after_decrypt.txt", "wb");   //복호화될 파일 주소

        crypt_both(0, fH, fI, key, iv);    //복호화

        fclose(fH);
        fclose(fI);
    }
    else
    {
        printf("<error> 1, 2 중 하나만 고를 수 있습니다.");
        return -1;
    }

    return 0;
}