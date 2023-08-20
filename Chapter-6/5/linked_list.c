#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/atomic.h>
#include <linux/errno.h>
#include <linux/slab.h>

LIST_HEAD(funky_head);

typedef struct _funky_struct {

    int some_val;
    struct list_head list;
} funky;

static int __init my_init(void) {

    funky * ff; 

    for(int i = 0; i < 5; i++){
        
       ff = kmalloc(sizeof(funky), GFP_KERNEL);
       ff->some_val = i+1;
       list_add(&ff->list, &funky_head);
    }
    return 0;
}

static void __exit my_exit(void) {
    
    struct list_head *pos;
    struct list_head *tmp;

    list_for_each_safe(pos, tmp, &funky_head){
        
        funky *entry = list_entry(pos, funky, list);
        list_del(&entry->list);
        kfree(entry);
    }

    if (list_empty(&funky_head))
        pr_info("Successfully freed list\n");
    else
        pr_info("unsuccessfully freed list\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
