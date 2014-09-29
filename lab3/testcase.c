
#include "testcase.h"

/***test translating tDataNode[] into LinkTable******************************************************/
void testInit(tLinkTable *Node,tDataNode* menu)
{
    printf("testing initMenu:\n");
    Node=initMenu(menu);
    int len=0;
    len=getNodeLength(Node);
    if(len!=0)
    {
        printf("initMenu is Okay!\n\n");
    }
    else
    {
        printf("initMenu is error!\n\n");
    }
   
 
}

/***test getting cmd list****************************************************************************/
void testShowAll(tLinkTable *Node,tDataNode* menu)
{
    printf("testing showAllCmd:\n");
    Node=initMenu(menu);
    showAllCmd(Node);
    printf("showAllCmd is Okay!\n\n");
}

/***test get desc by cmd num******************************************************************************/
void testGetByNum(tLinkTable *Node,tDataNode* menu,int num)
{
    printf("testing getByNum:\n");
    printf("Your test cmd num is : %d\n",num);
    tDataNode* tData;
    Node=initMenu(menu);
    tData=getByNum(Node,num);
    if(tData!=NULL)
    {
        printf("%s - %s - %s\n", tData->cmd, tData->desc, tData->value);
        if(tData->handler != NULL)
        {
            tData->handler();
        } 
        printf("getByNum is Okay!\n\n");
    }
    else
    {
        printf("getByNum is error!\n\n");
    }
    
}

/***test get desc by cmd**********************************************************************************/
void testGetByCmd(tLinkTable *Node,tDataNode* menu,char * cmd)
{
    printf("testing getByCmd:\n");
    printf("Your test cmd is : %s\n",cmd);
    tDataNode* tData;
    Node=initMenu(menu);
    tData=getByCmd(Node,cmd);
    if(tData!=NULL)
    {
        printf("%s - %s - %s\n", tData->cmd, tData->desc, tData->value);
        if(tData->handler != NULL)
        {
            tData->handler();
        } 
        printf("getByCmd is Okay!\n\n");
    }
    else
    {
        printf("getByCmd is error!\n\n");
    }
    
}

/***test get Length of the tDataNode variable*************************************************************/
void testGetNodeLength(tLinkTable *Node,tDataNode* menu)
{
    printf("testing getNodeLength:\n");
    Node=initMenu(menu); 
    int len=0;
    len=getNodeLength(Node);
    if(len!=0)
    {
	printf("the length is : %d\n",len);        
        printf("getNodeLength is Okay!\n\n");
    }
    else
    {
        printf("getNodeLength is error!\n\n");
    }
}

