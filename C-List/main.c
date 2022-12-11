#include "mylist.h"

int main(void)
{
    Element *a=create_element(1);
    Element *b=create_element(2);
    Element *c=create_element(3);
    Element *d=create_element(4);

    List *L = create_list();

    printf("[+] Add a,b elements\n");
    append_back(L, a);
    append_back(L, b);

    printf("[+] Size of the list : %d\n", get_list_size(L));

    printf("[+] Add c element\n");
    append_back(L, c);

    printf("[+] Content of the list :\n");
    print_list(L);
    printf("\n");

    printf("[+] Delete c\n");
    free(pop_back(L));

    printf("[+] Delete a\n");
    free(pop_front(L));

    printf("[+] Content of the list :\n");
    print_list(L);
    printf("\n");

    printf("[+] Add d\n");
    append_front(L,d);

    printf("[++] Contenu final :\n");
    print_list(L);
    destroy_list(L);
    return 0;
}

