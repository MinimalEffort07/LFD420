#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/page-flags.h>
#include <linux/init.h>
#include <linux/mm.h>

LIST_HEAD()

static int __init my_init(void) {

    return 0;
}

static void __exit my_exit(void) {

    pr_info("Unloading Module 1\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
