#include <stdlib.h>
#include <stdio.h>
#include "welcome.h"
#include "login.h"
#include "register.h"

int main(){
    int num;
    while(1){
        welcome();//菜单界面
        
        scanf("%d",&num);//读取用户输入功能
        switch (num)
        {
        case 1:
            num = login();
            break;
        case 2:
            num = register1();
            break;
        case 3:
            break;
        case 0:
            break;
        default:
            system("clear");
            printf("输入有误！请重新输入：\n");
            break;
        }
        if(num == 3){
            break;
        }

    }
    return 0;
}