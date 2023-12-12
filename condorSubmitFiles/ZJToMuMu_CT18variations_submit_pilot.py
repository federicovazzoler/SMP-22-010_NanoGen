executable = /nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen/run_config_condor.sh 
arguments = /nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen/configs/ZJToMuMu_CT18variations_condorJob.py $(seed) /nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen/condorJobs/ZJToMuMu_CT18variations_pilot 
log = /nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen/condorJobs/ZJToMuMu_CT18variations_pilot/log_$(seed).txt
output = /nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen/condorJobs/ZJToMuMu_CT18variations_pilot/out_$(seed).txt
error = /nfs/dust/cms/user/vazzolef/NanoGEN/CMSSW_10_6_32_patch1/src/Configuration/SMP-22-010_NanoGen/condorJobs/ZJToMuMu_CT18variations_pilot/err_$(seed).txt
JobBatchName = ZJToMuMu_CT18variations_pilot
queue seed from (
1
2
3
)
