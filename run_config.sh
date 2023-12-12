#! /bin/bash

config=${1}

workFld=NanoGEN/$(basename "$config" .py)
mkdir -p ${workFld}
cp ${config} ${workFld}/cfg.py

cd ${workFld}
if [ -f job.log ]; then rm job.log; fi
cmsenv
time cmsRun cfg.py | tee -a job.log 2>&1
exit 0 
