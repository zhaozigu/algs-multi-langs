// 单链表
#ifndef __LIST_H__
#define __LIST_H__

// 结点
typedef struct ListElmt_
{
  void *data;
  struct ListElmt_ *next;
} ListElmt;

// 链表
typedef struct List_
{
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  ListElmt *head;
  ListElmt *tail;
} List;

// 接口
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(list, element) ((element) == (list)->tail ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
#endif
