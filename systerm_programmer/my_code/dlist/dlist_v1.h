/*
version1:ʵ�����ݵķ�װ����.h�������ڵ�����ݽṹ����.c��ʵ�־���Ľڵ�ṹ��Ҫ���ݽṹ�ṩ��Ӧ�Ĳ���������
version2:ʵ��ͨ���ԡ�1.���ڵ����ݽṹ�е���������Ƴ�void *data 2.ͨ�õĺ�������ֵ����  3.ͨ�õĺ������������˫����Ĳ�����
version3:
���˫����ά��һ��ͷ��㣬ͷ�ڵ��������������Ľ�������pre��ָ��Ϊ�գ�nextָ��ָ������ĵ�һ�������ڵ�.
*/


#include <stdio.h>
#include <stdlib.h>

#ifndef dlist.h
#define dlist.h

#ifdef __cplusplus                          //version2���Ǻ�������C++�б�����
extern "C"
{
#endif
/*˫����Ľ��ṹ*/
struct _Dlist;                         //version1��ʵ�����ݷ�װ       
typedef struct _Dlist dlist_node;          //version1

typedef enum  _dlist_ret
{
	DLIST_RET_OK,
	DLIST_RET_OOM,
	DLIST_RET_STOP,
	DLIST_RET_PARAMS,
	DLIST_RET_FAIL,
}DlistRet;

typedef DlistRet (*dlist_data_print)(void *data);

/*˫����Ĳ���*/
	dlist_node* dlist_creat(void);                   //version1
	void dlist_destroy(dlist* head);      //version1

	//DlistRet dlist_init(dlist_node* head, int length);
	DlistRet dlist_insert(dlist* head, int location, void *data);
	//DlistRet *dlist_delte(dlist_node* head, int location);
	//dlist_ret dlist_getnode(dlist_node* head, void *data);
	//dlist_ret dlist_setnode(dlist_node* head, int location, void *data);
	DlistRet dlist_visit(dlist* head, dlist_data_print);
	size_t dlist_length(dlist* head);

#ifdef __cplusplus                        //version2
}
#endif

