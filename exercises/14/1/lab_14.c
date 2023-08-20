#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/delay.h>

static int __init my_init(void) {

    pr_info("Loaded mutex module, export mutex: %p\n", &my_mutex);
    return 0;
}

static void __exit my_exit(void) {

    pr_info("unloading mutex module\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
