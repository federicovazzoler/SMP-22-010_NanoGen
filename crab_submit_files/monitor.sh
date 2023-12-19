#!/bin/bash

WRKFLD="/nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen"

source ${WRKFLD}/setup_naf.sh
cmsenv

clear

#crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt_pilot
#echo ""
#
#crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToMuMU-H2BugFix-PDFVarExt_pilot
#echo ""
#
#crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt_1000ev_pilot
#echo ""
#
#crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt_5000ev_pilot
#echo ""
#
#crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToMuMu-H2BugFix-PDFVarExt_1000ev_pilot
#echo ""
#
#crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToMuMu-H2BugFix-PDFVarExt_5000ev_pilot
#echo ""

crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt
echo ""

crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToMuMu-H2BugFix-PDFVarExt
echo ""


crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt_ext1
echo ""

crab status -d ${WRKFLD}/crab_submit_files/crab_projects/crab_ZJToMuMu-H2BugFix-PDFVarExt_ext1
echo ""

exit 0
