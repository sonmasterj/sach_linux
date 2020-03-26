#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>

#define DRIVER_AUTHOR "Sonmaster"
#define DRIVER_DESC "Sample character device"
#define DRIVER_VERSION "1.0"

struct  _vchar_drv{
    dev_t dev_num;
    struct  class *dev_class;
    struct device *dev;
    
}vchar_drv;

/*
device specific -START
*/
/* ham khoi tao thiet bi*/
/* ham giai phong thiet bi */

/* ham doc tu cac thanh ghi du lieu cua thiet bi */

/* ham ghi vao cac thanh ghi du lieu cua thiet bi */

/* ham doc tu cac thanh ghi trang thai cua thiet bi */

/* ham ghi vao cac thanh ghi dieu khien cua thiet bi */

/* ham xu ly tin hieu ngat gui tu thiet bi */

/******************************* device specific - END *****************************/


/******************************** OS specific - START *******************************/
/* cac ham entry points */

/* ham khoi tao driver */
static int __init vchar_driver_init(void)
{
	/* cap phat device number */
    int ret=0;
    //ret=register_chrdev_region(vchar_drv.dev_num,1,"char_device"); //cap phat tinh
    ret=alloc_chrdev_region(&vchar_drv.dev_num,0,1,"char_driver");
    if(ret<0){
        printk("failed to resgiter device number\n");
        goto failed_resgister_devnum;
    }
    printk("alloc device number %d %d \n",MAJOR(vchar_drv.dev_num),MINOR(vchar_drv.dev_num));
	/* tao device file */
    vchar_drv.dev_class=class_create(THIS_MODULE,"class_char_dev");
    if(vchar_drv.dev_class==NULL){
        printk("failed to creat device class\n");
        goto failed_create_class;
    }
    vchar_drv.dev=device_create(vchar_drv.dev_class,NULL,vchar_drv.dev_num,NULL,"char_driver");
    if(IS_ERR(vchar_drv.dev)){
        printk("failed cho create a device\n");
        goto failed_create_device;
    }

	/* cap phat bo nho cho cac cau truc du lieu cua driver va khoi tao */

	/* khoi tao thiet bi vat ly */

	/* dang ky cac entry point voi kernel */

	/* dang ky ham xu ly ngat */

	printk("Initialize vchar driver successfully\n");
	return 0;
    failed_resgister_devnum:
        return ret;
    failed_create_class:
        unregister_chrdev_region(vchar_drv.dev_num,1);
    failed_create_device:
        class_destroy(vchar_drv.dev_class);
}

/* ham ket thuc driver */
static void __exit vchar_driver_exit(void)
{
	/* huy dang ky xu ly ngat */

	/* huy dang ky entry point voi kernel */

	/* giai phong thiet bi vat ly */

	/* giai phong bo nho da cap phat cau truc du lieu cua driver */

	/* xoa bo device file */
    device_destroy(vchar_drv.dev_class,vchar_drv.dev_num);
    class_destroy(vchar_drv.dev_class);
	/* giai phong device number */
    unregister_chrdev_region(vchar_drv.dev_num,1);
	printk("Exit vchar driver\n");
}
/********************************* OS specific - END ********************************/

module_init(vchar_driver_init);
module_exit(vchar_driver_exit);

MODULE_LICENSE("GPL"); /* giay phep su dung cua module */
MODULE_AUTHOR(DRIVER_AUTHOR); /* tac gia cua module */
MODULE_DESCRIPTION(DRIVER_DESC); /* mo ta chuc nang cua module */
MODULE_VERSION(DRIVER_VERSION); /* mo ta phien ban cuar module */
MODULE_SUPPORTED_DEVICE("testdevice"); /* kieu device ma module ho tro */
