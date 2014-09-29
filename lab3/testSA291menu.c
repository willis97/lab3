#include <stdio.h>
#include <stdlib.h>
#include "testcase.h"
#define CMD_MAX_LEN 128

tLinkTable *Node;

int getHelp()
{
    showAllCmd(Node);
    return 1;
}


tDataNode menu[] =
{
    {NULL,0,"help", "this is help!","help you find cmd", getHelp},
    {NULL,1,"fname", "menu's file name.", "SA291menu.c", NULL},
    {NULL,2,"author", "menu's principal author.","SA14226291 Zhangqingmei", NULL},
    {NULL,3,"subsyname", "menu's subsystem name.", "SA291menu", NULL},
    {NULL,4,"modname", "menu's module name.", "SA291menu", NULL},
    {NULL,5,"language", "using programming language.", "c", NULL},
    {NULL,6,"target", "menu's target environment.", "any", NULL},
    {NULL,7,"desc", "menu's description.", "this is a menu program", NULL},
    {NULL,8,"time", "menu's creation time.","2014/08/31 8:00", NULL},
    {NULL,9,"where", "the place of the menu.","USTC", NULL},
    {NULL,10,"isava", "menu's availability.","Yes", NULL}
   
};


void main()
{
    testGetNodeLength(Node,menu);
    testInit(Node,menu);
    testShowAll(Node,menu);
    Node=initMenu(menu);
    char cmd[CMD_MAX_LEN]="fname";
    int num=0;
    testGetByCmd(Node,menu,cmd);
    testGetByNum(Node,menu,num);

}
