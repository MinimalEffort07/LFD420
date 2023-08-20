#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <asm/current.h>



static int __init my_init(void) {

    struct mm_struct *cur_mm = get_current()->mm;

    struct vm_area_struct *tmp;

    VMA_ITERATOR(vmi, cur_mm, 0);

    for_each_vma(vmi, tmp) {

        pr_info("tmp: %p\n", tmp->vm_mm);
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
