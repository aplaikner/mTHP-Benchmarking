./test04 &
pid=$!
cat /proc/$pid/smaps
sleep 3
