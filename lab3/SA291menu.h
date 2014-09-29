/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  SA291menu.h                                                          */
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

#include "linktable.h"

typedef struct DataNode
{  
    tLinkTableNode * pNext;
    int     num;	
    char*   cmd;
    char*   desc;
    char*   value;
    int     (*handler)();  
} tDataNode;

/***translate tDataNode[] into LinkTable**************************************************************/
tLinkTable *initMenu(tDataNode *menu);

/***get cmd list*************************************************************************************/
int showAllCmd(tLinkTable * head);

/***get desc by cmd num******************************************************************************/
tDataNode* getByNum(tLinkTable * head, int num);

/***get desc by cmd**********************************************************************************/
tDataNode* getByCmd(tLinkTable * head, char * cmd);

/***get Length of the tDataNode variable*************************************************************/
int getNodeLength(tLinkTable * head);




