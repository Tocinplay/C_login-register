#include "register.h"
#include "user.h"

int register1(){
    //定义一个结构体reuser<=>register user 来存储用户名和密码
    User reuser;

    printf("请输入用户名:");
    scanf("%s",reuser.account);
    if(reuser.account[0] == '\0'){
        printf("输入字符为空！\n");
        return 0;
    }else if(strlen(reuser.account) > 24){
        printf("输入字符超过24个字符！\n");
        return 0;
    }
    

    printf("请输入密码:");
    scanf("%s",reuser.passwd);
    if(reuser.passwd[0] == '\0'){
        printf("输入字符为空！\n");
        return 0;
    }else if(strlen(reuser.passwd) > 24){
        printf("输入字符超过24个字符！\n");
        return 0;
    }
    

    //定义一个文件指针relo<=>request login去查询用户输入的账户
    FILE *relo = fopen("./passwd","a+");
    if(relo == NULL){
        printf("账户密码文件打开失败\n");
        return 0;
    }

    //定义ac字符串组接收并查询账户是否已经注册
    char ac[50];
    //判断用户是否存在
    int userExist = 0;

    while(fgets(ac,49,relo) != NULL){
        ac[strlen(ac) - 1] = '\0';//移除换行符

            if(strcmp(strtok(ac,":"),reuser.account) == 0){
                printf("用户%s已经存在\n",reuser.account);
                userExist = 1;
                break;
            }
        
    }
    if(!userExist){
            fprintf(relo,"\n%s:%s\n",reuser.account,reuser.passwd);
            printf("用户%s注册成功\n",reuser.account);
        }
    if(fclose(relo) == -1){
        printf("文件关闭失败！\n");
    }
    return 0;
}