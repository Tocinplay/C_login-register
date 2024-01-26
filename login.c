#include "login.h"
#include "user.h"

int login(){
    //定义一个结构体louser<=>loginuser 来存储用户名和密码
    User louser;

    printf("请输入用户名:");
    scanf("%s",louser.account);
    if(louser.account[0] == '\0'){
        printf("输入字符为空！\n");
        return 0;
    }else if(strlen(louser.account) > 24){
        printf("输入字符超过24个字符！\n");
        return 0;
    }
    //printf("%s = %ld\n",louser.account,strlen(louser.account));

    printf("请输入密码:");
    scanf("%s",louser.passwd);
    if(louser.passwd[0] == '\0'){
        printf("输入字符为空！\n");
        return 0;
    }else if(strlen(louser.passwd) > 24){
        printf("输入字符超过24个字符！\n");
        return 0;
    }
    //printf("%s = %ld\n",louser.passwd,strlen(louser.passwd));

    //定义一个文件指针relo<=>request login去查询用户输入的账户和密码
    FILE *relo = fopen("./passwd","r");
    if(relo == NULL){
        printf("账户密码文件打开失败\n");
        return 0;
    }

    //定义字符串组来存储读出的一行账号密码
    char acwd[50];
    int loginResult = 0;
    //确保fgets取出来的字符串不为空
    while(fgets(acwd,49,relo) != NULL){
        //if判断当文件没有读到末尾
        if(!feof(relo)){
            acwd[strlen(acwd) - 1] = '\0';
            //printf("%s = %ld\n",acwd,strlen(acwd));

            //分割字符":"取出账号和密码
            char *acc = strtok(acwd,":");//账号acc
            char *pawd = strtok(NULL,":");//密码pawd

            if(acc != NULL && pawd != NULL && strcmp(acc,louser.account) == 0 && strcmp(pawd,louser.passwd) == 0){
                printf("用户%s登录成功！\n",louser.account);
                loginResult = 3;
                break;
            }

        }
    }
    if(loginResult == 0){
        printf("登录失败，账号或密码不正确\n");
        
    }
    if(fclose(relo) == -1){
        printf("文件关闭失败！\n");
    }
    return loginResult;
}