#!/bin/bash

# Put the system under stress
#
# -c 8   -- Fork off 8 CPU intensive processes
# -i 4   -- Fork off 4 I/O intensive processes
# -m 6   -- Fork off 6 Memory intensive processes
# -t 20s -- Run the stress test for 20 seconds

sudo apt install stress stress-ng -y

stress -c 8 -i 4 -m 6 -t 20s
