#include <stdio.h>
#include "list.h"


struct object
{
    int id;
    char name[16];

    struct list_head node;
};


//------------------------------------------------------------------------------
void list_add_example()
{
    LIST_HEAD(obj_list);


    struct object obj1 = {
        .id = 1,
        .name = "obj1",
    };
    list_add(&obj1.node, &obj_list);

    struct object obj2 = {
        .id = 2,
        .name = "obj2",
    };
    list_add(&obj2.node, &obj_list);

    struct object obj3 = {
        .id = 3,
        .name = "obj3",
    };
    list_add(&obj3.node, &obj_list);


    struct list_head* iter;
    list_for_each(iter, &obj_list) {
        struct object* obj = list_entry(iter, struct object, node);
        printf("%s\n", obj->name);
    }
}

void list_add_tail_example()
{
    LIST_HEAD(obj_list);


    struct object obj1 = {
        .id = 1,
        .name = "obj1",
    };
    list_add_tail(&obj1.node, &obj_list);

    struct object obj2 = {
        .id = 2,
        .name = "obj2",
    };
    list_add_tail(&obj2.node, &obj_list);

    struct object obj3 = {
        .id = 3,
        .name = "obj3",
    };
    list_add_tail(&obj3.node, &obj_list);


    struct list_head* iter;
    list_for_each(iter, &obj_list) {
        struct object* obj = list_entry(iter, struct object, node);
        printf("%s\n", obj->name);
    }
}

void list_del_example()
{
    LIST_HEAD(obj_list);


    struct object obj1 = {
        .id = 1,
        .name = "obj1",
    };
    list_add_tail(&obj1.node, &obj_list);

    struct object obj2 = {
        .id = 2,
        .name = "obj2",
    };
    list_add_tail(&obj2.node, &obj_list);

    struct object obj3 = {
        .id = 3,
        .name = "obj3",
    };
    list_add_tail(&obj3.node, &obj_list);


    //--------------------------//

    // list_del - deletes entry from list.
    list_del(&obj2.node);

    //--------------------------//


    struct list_head* iter;
    list_for_each(iter, &obj_list) {
        struct object* obj = list_entry(iter, struct object, node);
        printf("%s\n", obj->name);
    }
}

//------------------------------------------------------------------------------

int main()
{
    list_add_example();
    return 0;
}

