1/ make data thread, use mutex to lock and unlock. while done, use notify_one/all to notify use.
2/ use data thread, use unique_lock of mutex to wait for condition, while got data, unique_lock can do unlock as soon.
