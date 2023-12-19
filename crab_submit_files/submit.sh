#!/bin/bash

## Pilot
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToEE-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt_1000ev_pilot.py
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToEE-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt_5000ev_pilot.py
#
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToMuMu-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt_1000ev_pilot.py
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToMuMu-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt_5000ev_pilot.py

#######

## First batch 10000 jobs --> 10M ev
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToEE-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt.py
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToMuMu-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt.py

## resubmit first batch and submit new one
#crab resubmit crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt
#crab resubmit crab_projects/crab_ZJToMuMu-H2BugFix-PDFVarExt

## Second batch 10000 jobs --> 20M ev
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToEE-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt.py
#crab submit crab_submit_Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToMuMu-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt.py

## resubmit second batch
crab resubmit crab_projects/crab_ZJToEE-H2BugFix-PDFVarExt_ext1
crab resubmit crab_projects/crab_ZJToMuMu-H2BugFix-PDFVarExt_ext1
