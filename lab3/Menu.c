/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  SA291menu.c                                                          */
/*  PRINCIPAL AUTHOR      :  Zhangqingmei                                                         */
/*  SUBSYSTEM NAME        :  SA291menu                                                            */
/*  MODULE NAME           :  SA291menu                                                            */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/22                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Zhangqingmei, 2014/09/22
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "SA291menu.h"
#include "linktable.h"

#define CMD_MAX_LEN 128

tLinkTable *Node;

int getHelp()
{
    showAllCmd(Node);
    return 1;
}

/***translate char* variable into int variable ************************************************************/
int StringToInt(const char *s)
{   
    int n = 0;   
    int i = 0;   
    while (s[i] != '\0')    
    {        
        n *= 10;        
        n += s[i] - '0';
        i++;    
    }    
    return n;
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


main()
{
   /* cmd line begins */  
    Node=initMenu(menu);
    printf("Hint: Please Input a cmd or cmd num, and exit by input 'exit'\n");
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        tDataNode *p;
        printf("menu> ");
        scanf("%s", cmd);
        if(cmd == NULL) 
        {
            printf("This is a wrong cmd\n");
            continue;
        }
        if(!strcmp(cmd, "exit") || !strcmp(cmd, "-1")) 
        {
            return 0;
        }
        if((strcmp(cmd, "9")<=0)&& (strcmp(cmd, "0")>=0))
        {
            int num=StringToInt(cmd);
            p=getByNum(Node,num);
        }
        else
        {
            p=getByCmd(Node,cmd); 
        }
        if(p!=NULL)
        {
            printf("%s - %s - %s\n", p->cmd, p->desc, p->value);
            if(p->handler != NULL)
            {
                p->handler();
            } 
        }
        else
        {
            printf("This is a wrong cmd\n");
            continue;
        }
    }
}


