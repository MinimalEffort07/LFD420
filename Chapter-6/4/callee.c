#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/init.h>


struct task_struct *p;
struct task_struct *t;

int funky_func(void) {

    pr_info("You called funky func\n");
    return 0;
}

static int __init module1_entry(void) {

    pr_info("Loaded Module 1\n");

    return 0;
}

static void __exit module1_exit(void) {

    pr_info("Unloading Module 1\n");
}

module_init(module1_entry);
module_exit(module1_exit);

EXPORT_SYMBOL(funky_func);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
