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
/*  DESCRIPTION           :  interface of menu                                                    */
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



/***translate tDataNode[] into LinkTable*************************************************************/
tLinkTable *initMenu(tDataNode *menu)
{
    tLinkTable * mhead = CreateLinkTable();
    int i=0;
    for(i=0;i<Length(menu);i++)
    {
         AddLinkTableNode(mhead,(tLinkTableNode *)&menu[i]);
    }
    return mhead;
}

/***get Length of the tDataNode variable which have already not been initialized yet*******************/
int Length(tDataNode * menu)
{
    int len=0;
    while(menu[len].cmd!=NULL)
    {
        len++;
    }
    return len;
}

/***get cmd list**************************************************************************************/
int showAllCmd(tLinkTable * head)
{
    printf("cmd list:\n");
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%d - %s - %s\n", pNode->num, pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}


/***get desc by cmd***********************************************************************************/
tDataNode* getByNum(tLinkTable * head, int num)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(pNode->num==num)
        {
            return  pNode;  
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return NULL;
}



/***get desc by cmd num********************************************************************************/
tDataNode* getByCmd(tLinkTable * head, char * cmd)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return NULL;
}

/***get Length of the tDataNode variable****************************************************************/
int getNodeLength(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    int len=0;
    while(pNode != NULL)
    {
        len++;
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return len;
}


