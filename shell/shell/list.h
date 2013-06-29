#include <stdio.h>


#define LIST_INCLUDE

struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};




static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

//newhead  ��prev  next֮��
static inline void __list_add(struct list_head *newhead,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = newhead;
	newhead->next = next;
	newhead->prev = prev;
	prev->next = newhead;
}
///////////////////////////////////
//--newhead  Insert after the head
static inline void list_add(struct list_head *newhead, struct list_head *head)
{
	__list_add(newhead, head, head->next);
}
///////////////////////////////////
//--newhead  Insert before the head������ʲô���������tail��next��ָ����head
static inline void list_add_tail(struct list_head *newhead, struct list_head *head)
{
	__list_add(newhead, head->prev, head);
}
//
//�����ڵ�һ���ڵ�ǰ�����һ���ڵ�
static inline void list_add_after_head(struct list_head *newhead, struct list_head *head)
{
	__list_add(newhead, head, head->next);
}

//static inline void __list_del(struct list_head * prev, struct list_head * next)
//{
//	next->prev = prev;
//	prev->next = next;
//}
/////////////////////////////////////
////delete  entry  itself
//static inline void __list_del_entry(struct list_head *entry)
//{
//	__list_del(entry->prev, entry->next);
//}
//
/////////////////////////////////////
////replace old   with   newhead
//static inline void list_replace(struct list_head *old,
//				struct list_head *newhead)
//{
//	newhead->next = old->next;
//	newhead->next->prev = newhead;
//	newhead->prev = old->prev;
//	newhead->prev->next = newhead;
//}
////�ж��Ƿ�Ϊ������,weiΪ�շ���1������Ϊ0
//static inline int list_ISempty(struct list_head * head)
//{
//	if(head == NULL || head->prev == head  || head->next == head)
//		return 1;
//	
//	return 0;
//}
//
//���ص�N���ڵ�ָ��,headΪ��0���ڵ�
static inline struct list_head * list_GetNUMn(struct list_head * head,int n)
{
	struct list_head * res=NULL;
	if(head == NULL || head->prev == head  || head->next == head)
		return NULL;
	if(n<=0)
		return head;
	int i=0;
	res=head;
	while( res->next  != head)
	{
		res=res->next;
		i++;
		if(i==n)
			return res;
	}
	return NULL;
}
//
//
//
//
//
//
//
//
//
//
//











