#!/usr/bin/env bash

# setup on naf-cms machines
if [[ "$(hostname)" == *"naf-cms"* ]]; then
  MDL_ver=cmssw/slc7_amd64_gcc900
  source /etc/profile.d/modules.sh
  module use -a /afs/desy.de/group/cms/modulefiles/
  module purge
  module load ${MDL_ver}
  # to use CRAB commands
  source /cvmfs/cms.cern.ch/common/crab-setup.sh
  # to use grid commands
  source /cvmfs/grid.desy.de/etc/profile.d/grid-ui-env.sh

  function cmsenv() {
    eval `scramv1 runtime -sh`
  }
  export -f cmsenv
# setup on bird-desy machines
elif [[ "$(hostname)" == *"bird"*"desy"* ]] || [[ "$(hostname)" == *"batch"*"desy"* ]]; then
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
