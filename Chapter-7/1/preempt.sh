#!/bin/bash

grep --color PREEMPT /boot/config-$(uname -r)
