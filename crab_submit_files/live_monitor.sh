#!/bin/bash

extStr=${1:-ext1}
sleepTime=${2:-30}

if [[ "$(hostname)" == *"naf-cms"* ]]; then
  WRKFLD="/nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen"
  source ${WRKFLD}/setup_naf.sh
elif [[ "$(hostname)" == *"lxplus"* ]]; then
  WRKFLD="/afs/cern.ch/user/f/fvazzole/work/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen/"
fi

cmsenv

while true; do
  clear

  echo ""
  date
  echo ""

  echo ""
  echo "Z -> ee (${extStr})"
  echo ""
  crab status -d "${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt_${extStr}"
  wait

  echo ""
  echo "Z -> mumu (${extStr})"
  echo ""
  crab status -d "${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToMuMu-H2BugFix-PDFVarExt_${extStr}"
  wait

  sleep ${sleepTime}
done
