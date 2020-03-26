#include <linux/module.h>
#define DRIVER_AUTHOR "SonMaster"
#define DRIVER_DESC " hello world"
static int __init init_hello(void){
    printk("hello World\n");
    return 0;
}
static void __exit exit_hello(void){
    printk("goodbye\n");
}
module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE("demo");