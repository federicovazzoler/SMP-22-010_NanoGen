#!/bin/bash

input_folder=${1}
if [ ! -d "${input_folder}" ]; then 
  echo "${input_folder} does not exists"
  exit 1
fi

condor_submit_name="condor_submit_delete_condor_jobs_in_$(basename ${input_folder}).sub"

# Generate Condor submit script
echo "Universe = vanilla" > ${condor_submit_name} 
echo "Executable = /bin/rm" >> ${condor_submit_name} 
echo "Arguments = -rf ${input_folder}/\$\$([ Process + 1 ])" >> ${condor_submit_name} 
echo "Queue 1000" >> ${condor_submit_name}

echo "Created ${condor_submit_name}"
