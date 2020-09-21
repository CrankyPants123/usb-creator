#
# Regular cron jobs for the kylin-usb-creator package
#
0 4	* * *	root	[ -x /usr/bin/kylin-usb-creator_maintenance ] && /usr/bin/kylin-usb-creator_maintenance
