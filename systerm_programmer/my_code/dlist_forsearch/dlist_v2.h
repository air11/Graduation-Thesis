#ifndef DLIST_H
#define DLIST_H

#ifdef __CPP			//��չ����ֱ�Ӹ�C++����
extern "C"
{
#endif

struct _dlist;			//ʵ�����ݷ�װ����dlist.c�ж���
typedef struct _dlist dlist; 

typedef enum dlist_ret		
{
	DLIST_RET_OK,
	DLIST_RET_OOM,
	DLIST_RET_STOP,
	DLIST_RET_PARAMS,
	DLIST_RET_FAIL,
}dlist_ret;

	
	typedef int (*dlist_data_sum_fun)(void* ctr, void* data);
	typedef void* (*dlist_data_compare_fun)(void* ctr, void* data);
	typedef dlist_ret (*dlist_data_print_fun)(void* data);
	 
	dlist* dlist_creat(void);
	dlist_ret dlist_destroy(dlist* head);       

        dlist_ret dlist_insert(dlist* head, size_t index, void* data);
	dlist_ret dlist_delete(dlist* head, size_t index);
	dlist_ret dlist_get_by_index(dlist* head, size_t index, void** data);
	dlist_ret dlist_set_by_index(dlist* head, size_t index, void* data);
	dlist_ret dlist_append(dlist* head, void* data);
	dlist_ret dlist_prepend(dlist* head, void* data);
	size_t dlist_length(dlist* head);
	dlist_ret dlist_print(dlist* head, dlist_data_print_fun print);
	/*dlist_ret dlist_forsearch(dlist* head, 
#ifdef SUM
				  dlist_data_sum_fun sum,
#elif COMPARE
				  dlist_data_compare_fun compare,
#endif
                                  void* ctr);*/
	int  dlist_foreach_find(dlist* head, dlist_data_compare_fun cmp, void* ctr);
	
#ifdef __CPP
}
#endif

#endif /*DLIST_H*/
