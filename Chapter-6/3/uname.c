#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/utsname.h>

static int __init my_init(void) {

    pr_info("Uname -a:\n"
            "sysname: %s\n"
            "nodename: %s\n"
            "release: %s\n"
            "version: %s\n"
            "machine: %s\n",
            init_uts_ns.name.sysname,
            init_uts_ns.name.nodename,
            init_uts_ns.name.release,
            init_uts_ns.name.version,
            init_uts_ns.name.machine);

    return 0;
}

static void __exit my_exit(void) {

    pr_info("Unloading utsname module\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
