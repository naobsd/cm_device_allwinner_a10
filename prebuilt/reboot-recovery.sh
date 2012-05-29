#!/system/bin/sh

echo -n boot-recovery | busybox dd of=/dev/block/nande count=1 conv=sync; sync; reboot
