#!/system/bin/sh

if busybox test ! -f /sdcard/recovery.cpio; then
	echo no /sdcard/recovery.cpio
	exit 1
fi

mkdir /mnt/recovery
mount -t ext4 /dev/block/nandf /mnt/recovery
busybox rm -fr /mnt/recovery/*
(cd /mnt/recovery && busybox cpio -idmuv < /sdcard/recovery.cpio)
umount /mnt/recovery
rmdir /mnt/recovery

echo done
