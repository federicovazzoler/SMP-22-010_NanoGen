from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'ZJToMuMu-H2BugFix-PDFVarExt_ext7'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.numCores = 1
config.JobType.maxMemoryMB = 2000
config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = '../configs/Zj_slc7_amd64_gcc10_CMSSW_12_3_1_ZJToMuMu-suggested-nnpdf31-ncalls-doublefsr-q139-finerGrid_v3-powheg-MiNNLO31-svn3900-ew-rwl6-j200-st2fix-ana-hoppetweights-ymax20-pdf3-PDFVarExt_1000ev_pilot_cfg.py'
config.JobType.allowUndistributedCMSSW = True

config.Data.outputPrimaryDataset = 'ZJToMuMu-H2BugFix-PDFVarExt_ext7'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 1000
NJOBS = 10000
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
#config.Data.outLFNDirBase = '/store/group/phys_smp/sin2O' 
config.Data.outLFNDirBase = '/store/group/phys_smp/ec/sin2O' 
config.Data.publication = False
config.Data.outputDatasetTag = 'NanoGEN'

config.Site.storageSite = 'T2_CH_CERN'
