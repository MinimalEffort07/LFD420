#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>

struct task_struct *p;
struct task_struct *t;

int funky_func(void);

static int __init module2_entry(void) {

    pr_info("Loaded Module 2; Attempting to load module 1\n");

    funky_func();

    return 0;
}

static void __exit module2_exit(void) {

    pr_info("Unloading Module 2\n");
}

module_init(module2_entry);
module_exit(module2_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
