#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>

static int __init my_init(void) {

    return 0;
}

static void __exit my_exit(void) {

    pr_info("BYE\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
