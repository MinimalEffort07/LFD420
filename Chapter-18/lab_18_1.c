#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/page-flags.h>
#include <linux/init.h>
#include <linux/mm.h>

static int __init my_init(void) {

    unsigned long num_physpages = get_num_physpages();

    unsigned long free_count = 0;

    for(unsigned long i = 0; i<num_physpages; i++){
        if(pfn_valid(i)){
            if (page_count(pfn_to_page(i)))
                    free_count++;
        }
    }
    pr_info("Number of pages: %ld\n", num_physpages);
    pr_info("Number of free pages: %ld\n", free_count);
    pr_info("Percentage free: %ld/%ld\n", free_count,num_physpages);

    return 0;
}

static void __exit my_exit(void) {

    pr_info("Unloading Module 1\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("MIN");
MODULE_LICENSE("GPL");
