#include <linux/module.h>
#include <linux/sched/signal.h>


struct task_struct *p;

static int __init my_init(void) {
    for_each_process(p) {
        pr_info("CLI: %s\n"
                "\tPID: %d\n"
                "\tState: %d\n\n", p->comm, p->tgid, p->__state);
    }
    return 0;
}

static void __exit my_exit(void) {

    pr_info("BYE\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
