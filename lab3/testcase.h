#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include "SA291menu.h"


/***test translating tDataNode[] into LinkTable******************************************************/
void testInit(tLinkTable *Node,tDataNode menu[]);

/***test getting cmd list****************************************************************************/
void testShowAll(tLinkTable *Node,tDataNode menu[]);

/***get desc by cmd num******************************************************************************/
void testGetByNum(tLinkTable *Node,tDataNode menu[],int num);

/***get desc by cmd**********************************************************************************/
void testGetByCmd(tLinkTable *Node,tDataNode menu[],char *cmd);

/***get Length of the tDataNode variable*************************************************************/
void testGetNodeLength(tLinkTable *Node,tDataNode menu[]);

