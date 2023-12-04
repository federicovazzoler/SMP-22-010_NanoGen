#! /bin/bash

config=${1}
seed=${2}
outfolder=${3}

# setup on naf-cms or bird-desy machines
if [[ "$(hostname)" == *"naf-cms"* ]] || [[ "$(hostname)" == *"bird"*"desy"* ]] || [[ "$(hostname)" == *"batch"*"desy"* ]]; then
  MDL_ver=cmssw/slc7_amd64_gcc900
  source /etc/profile.d/modules.sh
  module use -a /afs/desy.de/group/cms/modulefiles/
  module purge
  module load ${MDL_ver}
  function cmsenv() {
    eval `scramv1 runtime -sh`
  }
  export -f cmsenv
fi

mkdir -p ${outfolder}/${seed}; cd ${outfolder}/${seed}
cmsenv
cmsRun ${config} seed=${seed}
