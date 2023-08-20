#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/mutex.h>

extern struct mutex my_mutex; 

static int __init my_init(void) {
    
    if(!mutex_trylock(&my_mutex)){ 
        pr_err("Failed to obtain lock in module 2\n");
        return -1;
    }

    pr_info("SUCCESS: Obtained Lock in module 2\n");
    return 0;
}

static void __exit my_exit(void) {

    mutex_unlock(&my_mutex);
    pr_info("Unlocking module 2 mutex\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
