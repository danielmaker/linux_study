#include <stdio.h>
#include "list.h"
#include "hash.h"
#include "hashtable.h"

struct object
{
    int id;
    char name[16];

    struct hlist_node node;
};

//------------------------------------------------------------------------------
void print_hash_values()
{
    u8 bits = 3;
    int num_buckets = (1<<bits);
    int i = 0;
    for(i=0; i<num_buckets; ++i) {
        printf("hash_min(%d)=%d\n", i, hash_min(i, bits));
    }
}

void hashtable_example()
{
    // define a hash table with 2^3(=8) buckets
    DEFINE_HASHTABLE(htable, 3);
    // => struct hlist_head htable[8] = { [0 ... 7] = HLIST_HEAD_INIT };

    struct object obj1 = {
        .id = 1,
        .name = "obj1",
    };
    hash_add(htable, &obj1.node, obj1.id);

    struct object obj2 = {
        .id = 2,
        .name = "obj2",
    };
    hash_add(htable, &obj2.node, obj2.id);

    struct object obj3 = {
        .id = 3,
        .name = "obj3",
    };
    hash_add(htable, &obj3.node, obj3.id);

    struct object obj9 = {
        .id = 9,
        .name = "obj9",
    };
    hash_add(htable, &obj9.node, obj9.id);


    // find
    int key = 1;
    struct object* obj;
    hash_for_each_possible(htable, obj, node, key) {
        if(obj->id == key) {
            printf("key=%d => %s\n", key, obj->name);
        }
    }
}

void hash_del_example()
{
    // define a hash table with 2^3(=8) buckets
    DEFINE_HASHTABLE(htable, 3);
    // => struct hlist_head htable[8] = { [0 ... 7] = HLIST_HEAD_INIT };

    struct object obj1 = {
        .id = 1,
        .name = "obj1",
    };
    hash_add(htable, &obj1.node, obj1.id);

    struct object obj2 = {
        .id = 2,
        .name = "obj2",
    };
    hash_add(htable, &obj2.node, obj2.id);

    struct object obj3 = {
        .id = 3,
        .name = "obj3",
    };
    hash_add(htable, &obj3.node, obj3.id);

    struct object obj9 = {
        .id = 9,
        .name = "obj9",
    };
    hash_add(htable, &obj9.node, obj9.id);


    // find and del
    int key = 1;
    struct object* obj;
    hash_for_each_possible(htable, obj, node, key) {
        if(obj->id == key) {
            hash_del(&obj->node);
        }
    }


    int bkt;
    struct object* cur;
    hash_for_each(htable, bkt, cur, node) {
        printf("bucket[%d]=> %s\n", bkt, cur->name);
    }
}


void hashtable_show_buckets()
{
    // define a hash table with 2^3(=8) buckets
    DEFINE_HASHTABLE(htable, 3);
    // => struct hlist_head htable[8] = { [0 ... 7] = HLIST_HEAD_INIT };

    struct object obj1 = {
        .id = 1,
        .name = "obj1",
    };
    hash_add(htable, &obj1.node, obj1.id);

    struct object obj2 = {
        .id = 2,
        .name = "obj2",
    };
    hash_add(htable, &obj2.node, obj2.id);

    struct object obj3 = {
        .id = 3,
        .name = "obj3",
    };
    hash_add(htable, &obj3.node, obj3.id);

    struct object obj9 = {
        .id = 9,
        .name = "obj9",
    };
    hash_add(htable, &obj9.node, obj9.id);


    // int bkt;
    // struct object* cur;
    // hash_for_each(htable, bkt, cur, node) {
    //     printf("bucket[%d]=> %s\n", bkt, cur->name);
    // }

    // show hashtable buckets
    int i=0;
    for (i = 0; i < HASH_SIZE(htable); ++i)
    {
        if (!hlist_empty(&htable[i]))
        {
            printf("bucket[%d]=> ", i);

            struct object* obj;
            hlist_for_each_entry(obj, &htable[i], node) {
                printf("%s, ", obj->name);
            }
            printf("\n");
        }
    }
}

// Every bucket in the hashtable is a linked list which will hold all objects
// that are hashed to the same bucket.
void hash_add_same_key_example()
{
    // define a hash table with 2^3(=8) buckets
    DEFINE_HASHTABLE(htable, 3);
    // => struct hlist_head htable[8] = { [0 ... 7] = HLIST_HEAD_INIT };

    struct object obj1 = {
        .id = 0,
        .name = "obj1",
    };
    hash_add(htable, &obj1.node, obj1.id);

    struct object obj2 = {
        .id = 0,
        .name = "obj2",
    };
    hash_add(htable, &obj2.node, obj2.id);

    struct object obj3 = {
        .id = 0,
        .name = "obj3",
    };
    hash_add(htable, &obj3.node, obj3.id);

    int bkt;
    struct object* cur;
    hash_for_each(htable, bkt, cur, node) {
        printf("bucket[%d]=> %s\n", bkt, cur->name);
    }
}



//------------------------------------------------------------------------------

int main()
{
    hashtable_show_buckets();
    return 0;
}

