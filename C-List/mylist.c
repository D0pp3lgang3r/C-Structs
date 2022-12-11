#include "mylist.h"

Element *create_element(int value)
{
    Element *elt = malloc(sizeof(Element*));
    if (elt == NULL)
    {
        fprintf(stderr, "[-] Could not allocate an element in the memory\n");
        exit(EXIT_FAILURE);
    }
    elt->value = value;
    elt->next = NULL;
    return elt;
}

void destroy_element(Element *elt)
{
    free(elt->next);
}

List *create_list(void)
{
    List *l = malloc(sizeof(List*));
    if (l == NULL)
    {
        fprintf(stderr, "[-] Could not allocate a list in the memory\n");
        exit(EXIT_FAILURE);
    }
    l->first = NULL;
    return l;
}

void destroy_list(List *L)
{
    Element *f;
    while (L->first != NULL)
    {
        f = L->first;
        L->first = L->first->next;
        free(f);
    }
    free(L);
}

int is_list_empty(List *L)
{
    if (L->first == NULL)
        return 1;
    return 0;
}

int get_list_size(List *L)
{
    int size=0;
    if (!is_list_empty(L)) {
        Element *start = L->first;
        while (L->first != NULL)
        {
            L->first = L->first->next;
            size++;
        }
        L->first = start;
    }
    return size;
}

void print_list(List *L)
{
    Element *start = L->first;
    if (is_list_empty(L))
    {
        printf("[+] The list is empty");
        return;
    }
    while (L->first != NULL)
    {
        printf("[%d]", L->first->value);
        L->first = L->first->next;
    }
    L->first = start;
    printf("\n");
}


void append_back(List *L, Element *e)
{
    Element *start = L->first;
    if (!is_list_empty(L)) {
        while (L->first->next != NULL)
        {
            L->first = L->first->next;
        }
        if (!realloc(L->first->next, sizeof(Element*)))
            exit(EXIT_FAILURE);
        L->first->next = e;
        L->first = start;
    }
    else {
        L->first = e;
    }
}


void append_front(List *L, Element *e)
{
    Element *tmp;
    tmp = L->first;
    L->first = e;
    L->first->next = tmp;
}

Element *pop_front(List *L)
{
    Element *tmp = L->first;
    if (!is_list_empty(L))
        L->first = L->first->next;
    return tmp;
}

Element *pop_back(List *L)
{
    if (is_list_empty(L))
    {
        return NULL;
    }
    if (L->first->next == NULL)
    {
        free(L);
        L->first = NULL;
        return NULL;
    }
    Element *before = L->first;
    Element *tmp = L->first;

    while (tmp->next != NULL)
    {
        before=tmp;
        tmp = tmp->next;
    }
    before->next = NULL;
    return tmp;
}


