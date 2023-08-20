#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>

struct task_struct *p;
struct task_struct *t;

static int __init my_init(void) {

    for_each_process_thread(p,t){
        pr_info("Task: %d\n"
                "task PID: %d\n"
                "task state: %d\n"
                "task cmd: %s\n",
                t->tgid, t->pid, t->__state, t->comm);
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
